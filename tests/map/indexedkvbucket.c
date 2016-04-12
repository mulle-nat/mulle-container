#include <mulle_standalone_container/mulle_standalone_container.h>
#include <mulle_test_allocator/mulle_test_allocator.h>

#include <stdio.h>



static void   random_key( char  key[ 5])
{
   key[ 0] = rand() % 10 + '0';
   key[ 1] = rand() % 10 + '0';
   key[ 2] = rand() % 10 + '0';
   key[ 3] = rand() % 10 + '0';
   key[ 4] = 0;
}


struct mulle_container_keyvaluecallback   _CALLBACK;

#define CALLBACK   &_CALLBACK

static void   simple_fill_test()
{
   char                          key[ 5];
   struct _mulle_indexedkeyvaluebucket   *bucket;
   unsigned int                  i;
   struct _mulle_keyvaluepair    pair;
   
   bucket = _mulle_indexedkeyvaluebucket_create( 128, 0, CALLBACK, NULL);
   
   printf( "%ld\n", _mulle_indexedkeyvaluebucket_get_count( bucket));

   pair._key   = key;
   pair._value = key;
   
   for( i = 0; i < 100000; i++)
   {
      random_key( key);
      _mulle_indexedkeyvaluebucket_put( bucket, &pair, CALLBACK, NULL);
   }

   _mulle_indexedkeyvaluebucket_reset( bucket, CALLBACK, NULL);

   printf( "%ld\n", _mulle_indexedkeyvaluebucket_get_count( bucket));
   _mulle_indexedkeyvaluebucket_put( bucket, &pair, CALLBACK, NULL);
   printf( "%ld\n", _mulle_indexedkeyvaluebucket_get_count( bucket));
   _mulle_indexedkeyvaluebucket_free( bucket, CALLBACK, NULL);
}



int  main()
{
   _CALLBACK.keycallback   = mulle_container_keycallback_copied_cstring;
   _CALLBACK.valuecallback = mulle_container_valuecallback_copied_cstring;
   
   mulle_test_allocator_initialize();
   mulle_default_allocator        = mulle_test_allocator;
   mulle_test_allocator_dont_free = 1;
   
   simple_fill_test();

   mulle_test_allocator_reset();
}
