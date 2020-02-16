//
//  Copyright (C) 2011 Nat!, Mulle kybernetiK.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the following disclaimer in the documentation
//  and/or other materials provided with the distribution.
//
//  Neither the name of Mulle kybernetiK nor the names of its contributors
//  may be used to endorse or promote products derived from this software
//  without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
#ifndef mulle__set__h__
#define mulle__set__h__

#include "mulle-container-callback.h"
#include "mulle-container-operation.h"


#define MULLE_SET_FILL_SHIFT    2
#define MULLE_SET_MIN_SIZE      (1 << MULLE_SET_FILL_SHIFT)

// counts are unsigned int, the result multiplied by sizeof is size_t */

/* set is a primitive growing hashtable */
#define MULLE__SET_BASE              \
   void             **_storage;      \
   unsigned int     _count;          \
   unsigned int     _size

// NSSet/NSMutableSet/NSHashTable

struct mulle__set
{
   MULLE__SET_BASE;
};


#define MULLE__SETENUMERATOR_BASE   \
   void           **_curr;          \
   unsigned int   _left;            \
   void           *_notakey


struct mulle__setenumerator
{
   MULLE__SETENUMERATOR_BASE;
};


#pragma mark - setup and takedown

MULLE_C_NONNULL_THIRD
struct mulle__set   *_mulle__set_create( unsigned int capacity,
                                         size_t extra,
                                         struct mulle_container_keycallback *callback,
                                         struct mulle_allocator *allocator) ;

MULLE_C_NONNULL_FIRST_SECOND
void    _mulle__set_destroy( struct mulle__set *set,
                             struct mulle_container_keycallback *callback,
                             struct mulle_allocator *allocator);


MULLE_C_NONNULL_FIRST_THIRD
void    _mulle__set_init( struct mulle__set *set,
                          unsigned int capacity,
                          struct mulle_container_keycallback *callback,
                          struct mulle_allocator *allocator);

MULLE_C_NONNULL_FIRST_SECOND
void    _mulle__set_done( struct mulle__set *set,
                          struct mulle_container_keycallback *callback,
                          struct mulle_allocator *allocator);

// don't inline this (!)
MULLE_C_NONNULL_FIRST_SECOND
void   _mulle__set_reset( struct mulle__set *set,
                          struct mulle_container_keycallback *callback,
                          struct mulle_allocator *allocator);


#pragma mark - copying

MULLE_C_NONNULL_FIRST_SECOND_THIRD
int   _mulle__set_copy_items( struct mulle__set *dst,
                              struct mulle__set *src,
                              struct mulle_container_keycallback *callback,
                              struct mulle_allocator *allocator);

MULLE_C_NONNULL_FIRST_SECOND
struct mulle__set   *_mulle__set_copy( struct mulle__set *set,
                                       struct mulle_container_keycallback *callback,
                                       struct mulle_allocator *allocator);

#pragma mark - debugging

MULLE_C_NONNULL_FIRST_SECOND
char   *_mulle__set_describe( struct mulle__set *set,
                              struct mulle_container_keycallback *callback,
                              struct mulle_allocator *allocator);

#pragma mark - petty accessors


MULLE_C_NONNULL_FIRST
static inline unsigned int   _mulle__set_get_size( struct mulle__set *set)
{
   return( set->_size);
}


MULLE_C_NONNULL_FIRST
static inline unsigned int   _mulle__set_get_count( struct mulle__set *set)
{
   return( set->_count);
}


#pragma mark - query


MULLE_C_NONNULL_FIRST
static inline int  _mulle__set_is_full( struct mulle__set *set)
{
   unsigned int    size;

   size = set->_size;
   size = (size - (size >> MULLE_SET_FILL_SHIFT));  // full when 75% occupied
   return( set->_count >= size);
}

MULLE_C_NONNULL_FIRST
static inline int  _mulle__set_is_sparse( struct mulle__set *set)
{
   unsigned int    size;

   size = set->_size / 2;
   size = (size - (size >> MULLE_SET_FILL_SHIFT));  // full when 75% occupied
   return( set->_count < size);
}



#pragma mark - operations


MULLE_C_NONNULL_FIRST_THIRD
void   _mulle__set_set( struct mulle__set *set,
                        void *p,
                        struct mulle_container_keycallback *callback,
                        struct mulle_allocator *allocator);

MULLE_C_NONNULL_FIRST_THIRD
void    *_mulle__set_insert( struct mulle__set *set,
                             void *p,
                             struct mulle_container_keycallback *callback,
                             struct mulle_allocator *allocator);


MULLE_C_NONNULL_FIRST_THIRD
void   *_mulle__set_get( struct mulle__set *set,
                         void *p,
                         struct mulle_container_keycallback *callback);

MULLE_C_NONNULL_FIRST_THIRD
int  _mulle__set_remove( struct mulle__set *set,
                         void *p,
                         struct mulle_container_keycallback *callback,
                         struct mulle_allocator *allocator);

#pragma mark - interface for mulle_bigset

MULLE_C_NONNULL_FIRST_FOURTH
int   __mulle__set_remove( struct mulle__set *set,
                           void *p,
                           unsigned int hash,
                           struct mulle_container_keycallback *callback,
                           struct mulle_allocator *allocator);

MULLE_C_NONNULL_FIRST_FOURTH
void   *__mulle__set_get( struct mulle__set *set,
                          void *p,
                          unsigned int hash,
                          struct mulle_container_keycallback *callback);

MULLE_C_NONNULL_FIRST_FIFTH
void   *_mulle__set_write( struct mulle__set *set,
                           void *p,
                           unsigned int hash,
                           enum mulle_container_write_mode mode,
                           struct mulle_container_keycallback *callback,
                           struct mulle_allocator *allocator);


MULLE_C_NONNULL_FIRST_SECOND
static inline void  _mulle__set_shrink_if_needed( struct mulle__set *set,
                                                  struct mulle_container_keycallback *callback,
                                                  struct mulle_allocator *allocator)
{
   void   _mulle__set_shrink( struct mulle__set *set,
                              struct mulle_container_keycallback *callback,
                              struct mulle_allocator *allocator);

   if( _mulle__set_is_sparse( set))
      _mulle__set_shrink( set, callback, allocator);
}


#pragma mark - enumeration



MULLE_C_NONNULL_FIRST_SECOND
static inline struct mulle__setenumerator
   _mulle__set_enumerate( struct mulle__set *set,
                          struct mulle_container_keycallback *callback)
{
   struct mulle__setenumerator   rover;

   rover._left    = set->_count;
   rover._curr    = set->_storage;
   rover._notakey = callback->notakey;

   return( rover);
}


static inline struct mulle__setenumerator
   mulle__set_enumerate_nil( struct mulle__set *set)
{
   struct mulle__setenumerator   rover;

   if( set)
   {
      rover._left    = set->_count;
      rover._curr    = set->_storage;
   }
   else
      rover._left   = 0;

   rover._notakey = NULL;

   return( rover);
}


MULLE_C_NONNULL_FIRST
static inline void   *_mulle__setenumerator_next_nil( struct mulle__setenumerator *rover)
{
   void   *p;

   assert( rover->_notakey == NULL);

   if( ! rover->_left)
      return( NULL);

   for(;;)
   {
      p = *rover->_curr++;
      if( p)
      {
         rover->_left--;
         return( p);
      }
   }
}


MULLE_C_NONNULL_FIRST
static inline int   _mulle__setenumerator_next( struct mulle__setenumerator *rover,
                                                void **item)
{
   void   *p;

   if( ! rover->_left)
   {
      if( item)
         *item = rover->_notakey;  // useful for NSHashTableEnumeration
      return( 0);
   }

   for(;;)
   {
      p = *rover->_curr++;
      if( p != rover->_notakey)
      {
         rover->_left--;
         if( item)
            *item = p;
         return( 1);
      }
   }
}


static inline void   mulle__setenumerator_done( struct mulle__setenumerator *rover)
{
}

#endif
