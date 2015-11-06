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
#ifndef mulle_set__h__
#define mulle_set__h__

#include "_mulle_set.h"
#include "mulle_allocator.h"
#include "mulle_container_callback.h"


//
// a mulle_set is a mulle_hashtable, with callbacks added
// this makes a mulle_set more convenient, but also quite a
// bit bigger for small sets
//
#define MULLE_SET_BASE                              \
   _MULLE_SET_BASE;                                 \
   struct mulle_container_keycallback   _callback   \


struct mulle_set
{
   MULLE_SET_BASE;
};


#define MULLE_SETENUMERATOR_BASE   \
   _MULLE_SETENUMERATOR_BASE


struct  mulle_setenumerator
{
   MULLE_SETENUMERATOR_BASE;
};


struct mulle_set   *mulle_set_create( size_t capacity,
                                      struct mulle_container_keycallback *callback);

void   mulle_set_init( struct mulle_set *set,
                       size_t capacity,
                       struct mulle_container_keycallback *callback);


static inline void   mulle_set_done( struct mulle_set *set)
{
   _mulle_set_done( (struct _mulle_set *) set, &set->_callback);
}


static inline void   mulle_set_free( struct mulle_set *set)
{
   _mulle_set_free( (struct _mulle_set *) set, &set->_callback);
}


static inline void   mulle_set_reset( struct mulle_set *set)
{
   _mulle_set_reset( (struct _mulle_set *) set, &set->_callback);
}


static inline void   *mulle_set_get( struct mulle_set *set, void *p)
{
   return( _mulle_set_get( (struct _mulle_set *) set, &set->_callback, p));
}


static inline void   mulle_set_remove( struct mulle_set *set, void *p)
{
   _mulle_set_remove( (struct _mulle_set *) set, &set->_callback, p);
}


static inline size_t   mulle_set_count( struct mulle_set *set)
{
   return( _mulle_set_count( (struct _mulle_set *) set));
}


static inline struct mulle_set   *mulle_set_copy( struct mulle_set *set)
{
   return( (struct mulle_set *) _mulle_set_copy( (struct _mulle_set *) set, &set->_callback));
}


static inline struct mulle_setenumerator   mulle_set_enumerate( struct mulle_set *set)
{
   struct _mulle_setenumerator  rover;
   
   rover = _mulle_set_enumerate( (struct _mulle_set *) set, &set->_callback);
   return( *(struct mulle_setenumerator *) &rover);
}


static inline void   *mulle_setenumerator_next( struct mulle_setenumerator *rover)
{
   return( _mulle_setenumerator_next( (struct _mulle_setenumerator *) rover));
}


static inline void   mulle_setenumerator_done( struct mulle_setenumerator *rover)
{
   _mulle_setenumerator_done( (struct _mulle_setenumerator *) rover);
}


static inline void   mulle_set_put( struct mulle_set *set, void *p)
{
   _mulle_set_put( (struct _mulle_set *) set, p, &set->_callback);
}

#endif

