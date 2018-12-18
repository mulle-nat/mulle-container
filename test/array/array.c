//
//  main.c
//  test-array
//
//  Created by Nat! on 04.11.15.
//  Copyright (c) 2015 Nat! - Mulle kybernetiK.
//  Copyright (c) 2015 Codeon GmbH.
//  All rights reserved.
//

#include <mulle-container/mulle-container.h>
#include <mulle-testallocator/mulle-testallocator.h>

#include <stdio.h>


static void  simple( void)
{
   struct mulle_array              *array;
   struct mulle_arrayenumerator    rover;
   void                            *item;

   array = mulle_array_create( &mulle_container_keycallback_copied_cstring, NULL);
   mulle_array_add( array, "VfL");
   assert("VfL" != mulle_array_get( array, 0)); // must have been copied

   mulle_array_add( array, "Bochum");
   mulle_array_add( array, "1848");

   assert( mulle_array_get_count( array) == 3);

   assert( ! strcmp( "VfL", mulle_array_get( array, 0)));
   assert( ! strcmp( "Bochum", mulle_array_get( array, 1)));
   assert( ! strcmp( "1848", mulle_array_get( array, 2)));

   rover = mulle_array_enumerate( array);
   item = mulle_arrayenumerator_next( &rover);
   assert( item);
   assert( ! strcmp( "VfL", item));
   item = mulle_arrayenumerator_next( &rover);
   assert( item);
   assert( ! strcmp( "Bochum", item));
   item = mulle_arrayenumerator_next( &rover);
   assert( item);
   assert( ! strcmp( "1848", item));
   item = mulle_arrayenumerator_next( &rover);
   assert( !item);
   mulle_arrayenumerator_done( &rover);

   mulle_array_remove_last( array);
   assert( mulle_array_get_count( array) == 2);
   mulle_array_remove_last( array);
   assert( mulle_array_get_count( array) == 1);
   mulle_array_remove_last( array);
   assert( mulle_array_get_count( array) == 0);

   mulle_array_destroy( array);
}


static void  ephemeral( void)
{
   struct mulle_array   array;

   mulle_array_init( &array, 10, &mulle_container_keycallback_copied_cstring, NULL);
   mulle_array_add( &array, "VfL");
   mulle_array_is_full( &array);
   mulle_array_done( &array);
}



static void  grow( void)
{
   struct mulle_array   array;
   size_t               memo_size;
   void                 *memo_storage;
   size_t               i, n;

   mulle_array_init( &array, 10, &mulle_container_keycallback_copied_cstring, NULL);
   mulle_array_guarantee( &array, 20);
   assert( mulle_array_guaranteedsize( &array) >= 20);

   memo_size    = array._size;
   memo_storage = array._storage;

   n = mulle_array_guaranteedsize( &array);
   for( i = 0; i < n; i++)
   {
      mulle_array_add( &array, "VfL");
   }

   // guarantee means unchanging internal storage
   assert( mulle_array_guaranteedsize( &array) == 0);
   assert( array._size == memo_size);
   assert( array._storage == memo_storage);

   assert( mulle_array_is_full( &array) == 1);
   mulle_array_grow( &array);
   assert( mulle_array_is_full( &array) == 0);

   mulle_array_done( &array);
}


static void  notakeymarker( void)
{
   struct mulle_array              *array;
   struct mulle_arrayenumerator    rover;
   int                             item;
   size_t                          index;

   array = mulle_array_create( &mulle_container_keycallback_int, NULL);
   mulle_array_add_int( array, 0);
   mulle_array_add_int( array, 1);
   mulle_array_add_int( array, 2);

   assert( 0 == mulle_array_get_int( array, 0));
   assert( 1 == mulle_array_get_int( array, 1));
   assert( 2 == mulle_array_get_int( array, 2));

   assert( mulle_array_get_count( array) == 3);

   rover = mulle_array_enumerate( array);
   item = mulle_arrayenumerator_next_int( &rover);
   assert( 0 == item);
   item = mulle_arrayenumerator_next_int( &rover);
   assert( 1 == item);
   item = mulle_arrayenumerator_next_int( &rover);
   assert( 2 == item);
   item = mulle_arrayenumerator_next_int( &rover);
   assert( (int) mulle_container_keycallback_int.notakey == item);
   assert( mulle_container_keycallback_int.notakey == mulle_container_not_an_int_key);

   index = mulle_array_find_in_range_identical_int( array, 1, 0, 3);
   assert( index == 1);
   index = mulle_array_find_in_range_identical_int( array, 1, 0, 1);
   assert( index == mulle_not_found_e);
   mulle_arrayenumerator_done( &rover);
   mulle_array_destroy( array);
}


static void  copy( void)
{
   struct mulle_array   array;
   struct mulle_array   copy;

   mulle_array_init( &array, 0, &mulle_container_keycallback_copied_cstring, NULL);

   mulle_array_add( &array, "VfL");
   mulle_array_add( &array, "Bochum");
   mulle_array_add( &array, "1848");
   assert( mulle_array_get_count( &array) == 3);

   mulle_array_init( &copy, 0, &mulle_container_keycallback_copied_cstring, NULL);
   assert( mulle_array_get_count( &copy) == 0);
   mulle_array_add_array( &copy, &array);
   assert( mulle_array_get_count( &copy) == 3);
   assert( mulle_array_get_count( &array) == 3);
   assert( mulle_array_is_equal( &copy, &array));

   mulle_array_done( &copy);
   mulle_array_done( &array);
}


static void  find( void)
{
   struct mulle_array   array;
   unsigned long        found;
   char                 *s1;
   char                 *s2;
   char                 *s3;

   mulle_array_init( &array, 0, &mulle_container_keycallback_copied_cstring, NULL);

   found = mulle_array_find_in_range_identical( &array, "xxx", 0, 0);
   assert( found == mulle_not_found_e);

   mulle_array_add( &array, s1 = "VfL");
   mulle_array_add( &array, s2 = "Bochum");
   mulle_array_add( &array, s3 = "1848");

   found = mulle_array_find_in_range( &array, s1, 0, 0);
   assert( found ==  mulle_not_found_e);

   // can't happen since we use copied cstring!
   found = mulle_array_find_in_range_identical( &array, s1, 0, 3);
   assert( found ==  mulle_not_found_e);

   found = mulle_array_find_in_range( &array, s1, 0, 3);
   assert( found == 0);
   found = mulle_array_find_in_range( &array, s2, 0, 3);
   assert( found == 1);
   found = mulle_array_find_in_range( &array, s3, 0, 3);
   assert( found == 2);

   found = mulle_array_find_in_range( &array, s3, 2, 1);
   assert( found == 2);

   found = mulle_array_find_in_range( &array, s1, 1, 0);
   assert( found == mulle_not_found_e);

   mulle_array_done( &array);
}

// the mulle_testallocator detects and aborts on leaks
static void  run_test( void (*f)( void), char *name)
{
   mulle_testallocator_reset();
  // printf( "%s\n", name);
   (f)();
   mulle_testallocator_reset();
}


int main(int argc, const char * argv[])
{
   run_test( simple, "simple");
   run_test( ephemeral, "ephemeral");
   run_test( grow, "grow");
   run_test( notakeymarker, "notakeymarker");
   run_test( copy, "copy");
   run_test( find, "find");
   return( 0);
}
