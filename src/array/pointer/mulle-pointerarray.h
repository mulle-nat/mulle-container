//
//  mulle-pointerarray.h
//  mulle-container
//
//  Created by Nat! on 10.03.15.
//  Copyright (c) 2015 Mulle kybernetiK. All rights reserved.
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
#ifndef mulle_pointerarray_h__
#define mulle_pointerarray_h__

#include "mulle--pointerarray.h"
#include <assert.h>
#include <string.h>
#include <stdint.h>


//
// mulle_pointerarray adds _storage of allocator to
// mulle__pointerarray, otherwise its the same
//
#define MULLE_POINTERARRAY_BASE          \
   MULLE__POINTERARRAY_BASE;             \
   struct mulle_allocator   *allocator


struct mulle_pointerarray
{
   MULLE_POINTERARRAY_BASE;
};


MULLE_C_NONNULL_FIRST
static inline void   _mulle_pointerarray_init( struct mulle_pointerarray *array,
                                               unsigned int capacity,
                                               struct mulle_allocator *allocator)
{
   _mulle__pointerarray_init( (struct mulle__pointerarray *) array,
                              capacity,
                              allocator);

   array->allocator = allocator;
}


MULLE_C_NONNULL_FIRST
static inline void   _mulle_pointerarray_done( struct mulle_pointerarray *array)
{
   _mulle__pointerarray_done( (struct mulle__pointerarray *) array,
                              array->allocator);
}


static inline void   mulle_pointerarray_done( struct mulle_pointerarray *array)
{
   if( array)
      _mulle__pointerarray_done( (struct mulle__pointerarray *) array,
                                 array->allocator);
}


static inline struct mulle_pointerarray  *
   mulle_pointerarray_alloc( struct mulle_allocator *allocator)
{
   struct mulle_pointerarray   *array;

   array = mulle_allocator_malloc( allocator, sizeof( struct mulle_pointerarray));
   return( array);
}


static inline struct mulle_pointerarray *
   mulle_pointerarray_create( struct mulle_allocator *allocator)
{
   struct mulle_pointerarray   *array;

   array = mulle_pointerarray_alloc( allocator);
   _mulle_pointerarray_init( array, 0, allocator);
   return( array);
}

static inline void   mulle_pointerarray_destroy( struct mulle_pointerarray *array)
{
   if( array)
      mulle__pointerarray_destroy( (struct mulle__pointerarray *) array,
                                   array->allocator);
}


# pragma mark - petty accessors

MULLE_C_NONNULL_FIRST
static inline unsigned int
   _mulle_pointerarray_get_size( struct mulle_pointerarray *array)
{
   return( _mulle__pointerarray_get_size( (struct mulle__pointerarray *) array));
}


static inline unsigned int
   mulle_pointerarray_get_size( struct mulle_pointerarray *array)
{
   return( mulle__pointerarray_get_size( (struct mulle__pointerarray *) array));
}


MULLE_C_NONNULL_FIRST
static inline unsigned int
   _mulle_pointerarray_get_count( struct mulle_pointerarray *array)
{
   return( _mulle__pointerarray_get_count( (struct mulle__pointerarray *) array));
}


static inline unsigned int
   mulle_pointerarray_get_count( struct mulle_pointerarray *array)
{
   return( mulle__pointerarray_get_count( (struct mulle__pointerarray *) array));
}



MULLE_C_NONNULL_FIRST
static inline unsigned int
	_mulle_pointerarray_get_guaranteed_size( struct mulle_pointerarray *array)
{
   return( _mulle__pointerarray_get_guaranteed_size( (struct mulle__pointerarray *) array));
}


static inline unsigned int
	mulle_pointerarray_get_guaranteed_size( struct mulle__pointerarray *array)
{
   return( mulle__pointerarray_get_guaranteed_size( (struct mulle__pointerarray *) array));
}


MULLE_C_NONNULL_FIRST
static inline int
   _mulle_pointerarray_is_full( struct mulle_pointerarray *array)
{
   return( _mulle__pointerarray_is_full( (struct mulle__pointerarray *) array));
}


static inline int
   mulle_pointerarray_is_full( struct mulle_pointerarray *array)
{
   return( mulle__pointerarray_is_full( (struct mulle__pointerarray *) array));
}


MULLE_C_NONNULL_FIRST
static inline struct mulle_allocator *
	_mulle_pointerarray_get_allocator( struct mulle_pointerarray *array)
{
   return( array->allocator);
}


static inline struct mulle_allocator *
   mulle_pointerarray_get_allocator( struct mulle_pointerarray *array)
{
   return( array ? array->allocator : NULL);
}


# pragma mark - memory operations

MULLE_C_NONNULL_FIRST
static inline void **
   _mulle_pointerarray_guarantee( struct mulle_pointerarray *array,
                                  unsigned int length,
                                  struct mulle_allocator *allocator)
{
   return( _mulle__pointerarray_guarantee( (struct mulle__pointerarray *) array,
                                           length,
                                           allocator));
}


static inline void **
   mulle_pointerarray_guarantee( struct mulle_pointerarray *array,
                                 unsigned int length,
                                 struct mulle_allocator *allocator)
{
   return( mulle__pointerarray_guarantee( (struct mulle__pointerarray *) array,
                                          length,
                                          allocator));
}



MULLE_C_NONNULL_FIRST
static inline void
   _mulle_pointerarray_grow( struct mulle_pointerarray *array,
                             struct mulle_allocator *allocator)
{
   _mulle__pointerarray_grow( (struct mulle__pointerarray *) array,
                              allocator);
}

static inline void
   mulle_pointerarray_grow( struct mulle_pointerarray *array,
                             struct mulle_allocator *allocator)
{
   mulle__pointerarray_grow( (struct mulle__pointerarray *) array,
                              allocator);
}



MULLE_C_NONNULL_FIRST
static inline void
   _mulle_pointerarray_compact( struct mulle_pointerarray *array,
                                void *notakey)
{
   _mulle__pointerarray_compact( (struct mulle__pointerarray *) array, notakey);
}

static inline void
   mulle_pointerarray_compact( struct mulle_pointerarray *array,
                                void *notakey)
{
   mulle__pointerarray_compact( (struct mulle__pointerarray *) array, notakey);
}



# pragma mark - operations

MULLE_C_NONNULL_FIRST
static inline void
   _mulle_pointerarray_add_guaranteed( struct mulle_pointerarray *array,
                                           void *p)
{
   _mulle__pointerarray_add_guaranteed( (struct mulle__pointerarray *) array,
                                        p);
}


MULLE_C_NONNULL_FIRST
static inline void
	_mulle_pointerarray_add( struct mulle_pointerarray *array, void *p)
{
   _mulle__pointerarray_add( (struct mulle__pointerarray *) array,
                              p,
                              array->allocator);
}

static inline void
   mulle_pointerarray_add( struct mulle_pointerarray *array, void  *p)
{
   mulle__pointerarray_add( (struct mulle__pointerarray *) array,
                             p,
                             array->allocator);
}


MULLE_C_NONNULL_FIRST
static inline void  *
	_mulle_pointerarray_remove_last( struct mulle_pointerarray *array)
{
   return( _mulle__pointerarray_remove_last( (struct mulle__pointerarray *) array));
}

static inline void *
   mulle_pointerarray_remove_last( struct mulle_pointerarray *array)
{
   return( mulle__pointerarray_remove_last( (struct mulle__pointerarray *) array));
}



MULLE_C_NONNULL_FIRST
static inline void  *
	_mulle_pointerarray_get_last( struct mulle_pointerarray *array)
{
   return( _mulle__pointerarray_get_last( (struct mulle__pointerarray *) array));
}

static inline void  *
   mulle_pointerarray_get_last( struct mulle_pointerarray *array)
{
   return( mulle__pointerarray_get_last( (struct mulle__pointerarray *) array));
}



MULLE_C_NONNULL_FIRST
static inline void  *
	_mulle_pointerarray_get( struct mulle_pointerarray *array, unsigned int i)
{
   return( _mulle__pointerarray_get( (struct mulle__pointerarray *) array, i));
}


static inline void  *
   mulle_pointerarray_get( struct mulle_pointerarray *array, unsigned int i)
{
   return( mulle__pointerarray_get( (struct mulle__pointerarray *) array, i));
}


MULLE_C_NONNULL_FIRST_THIRD
static inline unsigned int
   _mulle_pointerarray_get_in_range( struct mulle_pointerarray *array,
                                     struct mulle_range range,
                                     void *buf)
{
   return( _mulle__pointerarray_get_in_range( (struct mulle__pointerarray *) array,
                                              range,
                                              buf));
}

static inline unsigned int
   mulle_pointerarray_get_in_range( struct mulle_pointerarray *array,
                                    struct mulle_range range,
                                    void *buf)
{
   return( mulle__pointerarray_get_in_range( (struct mulle__pointerarray *) array,
                                             range,
                                             buf));
}


MULLE_C_NONNULL_FIRST
static inline uintptr_t
	_mulle_pointerarray_find( struct mulle_pointerarray *array, void *p)
{
   return( _mulle__pointerarray_find( (struct mulle__pointerarray *) array,
                                      p));
}


static inline uintptr_t
   mulle_pointerarray_find( struct mulle_pointerarray *array, void *p)
{
   return( mulle__pointerarray_find( (struct mulle__pointerarray *) array, p));
}


MULLE_C_NONNULL_FIRST
static inline void   *_mulle_pointerarray_set( struct mulle_pointerarray *array,
                                               unsigned int i,
                                               void *p)
{
   return( _mulle__pointerarray_set( (struct mulle__pointerarray *) array,
                                     i,
                                     p));

}


static inline void   *mulle_pointerarray_set( struct mulle_pointerarray *array,
                                              unsigned int i,
                                              void *p)
{
   return( mulle__pointerarray_set( (struct mulle__pointerarray *) array,
                                     i,
                                     p));
}


MULLE_C_NONNULL_FIRST
static inline void
   _mulle_pointerarray_reset( struct mulle_pointerarray *array)
{
   _mulle__pointerarray_reset( (struct mulle__pointerarray *) array);
}


static inline void
   mulle_pointerarray_reset( struct mulle_pointerarray *array)
{
   mulle__pointerarray_reset( (struct mulle__pointerarray *) array);
}


#pragma mark - enumeration

#define MULLE_POINTERARRAYENUMERATOR_BASE MULLE__POINTERARRAYENUMERATOR_BASE

struct mulle_pointerarrayenumerator
{
   MULLE_POINTERARRAYENUMERATOR_BASE;
};


MULLE_C_NONNULL_FIRST
static inline struct mulle_pointerarrayenumerator
   _mulle_pointerarray_enumerate( struct mulle_pointerarray *array)
{
   struct mulle__pointerarrayenumerator   rover;

   rover = _mulle__pointerarray_enumerate( (struct mulle__pointerarray *) array);
   return( *(struct mulle_pointerarrayenumerator *) &rover);
}


static inline struct mulle_pointerarrayenumerator
   mulle_pointerarray_enumerate( struct mulle_pointerarray *array)
{
   struct mulle__pointerarrayenumerator   rover;

   rover = mulle__pointerarray_enumerate( (struct mulle__pointerarray *) array);
   return( *(struct mulle_pointerarrayenumerator *) &rover);
}


MULLE_C_NONNULL_FIRST
static inline int
	_mulle_pointerarrayenumerator_next( struct mulle_pointerarrayenumerator *rover, void **item)
{
   return( _mulle__pointerarrayenumerator_next( (struct mulle__pointerarrayenumerator *) rover,
                                                item));
}

static inline int
	mulle_pointerarrayenumerator_next( struct mulle_pointerarrayenumerator *rover, void **item)
{
   return( mulle__pointerarrayenumerator_next( (struct mulle__pointerarrayenumerator *) rover,
                                                item));
}


MULLE_C_NONNULL_FIRST
static inline void
	_mulle_pointerarrayenumerator_done( struct mulle_pointerarrayenumerator *rover)
{
}


static inline void
   mulle_pointerarrayenumerator_done( struct mulle_pointerarrayenumerator *rover)
{
}


#pragma mark - reverseenumeration

#define MULLE_POINTERARRAYREVERSEENUMERATOR_BASE  MULLE__POINTERARRAYREVERSEENUMERATOR_BASE

struct mulle_pointerarrayreverseenumerator
{
   MULLE_POINTERARRAYREVERSEENUMERATOR_BASE;
};


MULLE_C_NONNULL_FIRST
static inline struct  mulle_pointerarrayreverseenumerator
   _mulle_pointerarray_reverseenumerate( struct mulle_pointerarray *array)
{
   struct mulle__pointerarrayreverseenumerator   rover;

   rover = _mulle__pointerarray_reverseenumerate( (struct mulle__pointerarray *) array);
   return( *(struct mulle_pointerarrayreverseenumerator *) &rover);
}


static inline struct  mulle_pointerarrayreverseenumerator
   mulle_pointerarray_reverseenumerate( struct mulle_pointerarray *array)
{
   struct mulle__pointerarrayreverseenumerator   rover;

   rover = mulle__pointerarray_reverseenumerate( (struct mulle__pointerarray *) array);
   return( *(struct mulle_pointerarrayreverseenumerator *) &rover);
}


MULLE_C_NONNULL_FIRST
static inline int
	_mulle_pointerarrayreverseenumerator_next( struct mulle_pointerarrayreverseenumerator *rover,
                                              void **item)
{
   return( _mulle__pointerarrayreverseenumerator_next( (struct mulle__pointerarrayreverseenumerator *) rover,
                                                       item));
}

MULLE_C_NONNULL_FIRST
static inline int
	mulle_pointerarrayreverseenumerator_next( struct mulle_pointerarrayreverseenumerator *rover,
                                             void **item)
{
   return( mulle__pointerarrayreverseenumerator_next( (struct mulle__pointerarrayreverseenumerator *) rover,
                                                      item));
}


MULLE_C_NONNULL_FIRST
static inline void
	_mulle_pointerarrayreverseenumerator_done( struct mulle_pointerarrayreverseenumerator *rover)
{
}


static inline void
   mulle_pointerarrayreverseenumerator_done( struct mulle_pointerarrayreverseenumerator *rover)
{
}


#pragma mark - enumerator convenience

static inline int   mulle_pointerarray_member( struct mulle_pointerarray *array, void *p)
{
   return( mulle__pointerarray_member( (struct mulle__pointerarray *) array, p));
}

#endif
