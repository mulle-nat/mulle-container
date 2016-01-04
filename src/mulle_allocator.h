//  mulle-container
//
//  Created by Nat! on 02/11/15.
//  Copyright © 2015 Mulle kybernetiK. All rights reserved.
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
#ifndef mulle_allocator_h
#define mulle_allocator_h

#include <stdint.h>
#include <stddef.h>


//
// _mulle_allocator just a way to pass around the memory scheme du jour
// to containers. Eventually this header will wind up in a separate
// mulle_c_containers project,
//
struct mulle_allocator
{
   void   *(*calloc)( size_t, size_t);
   void   *(*realloc)( void *, size_t);
   void   (*free)( void *);
};

extern struct mulle_allocator   mulle_default_allocator;
extern struct mulle_allocator   mulle_stdlib_allocator;

typedef void  *(*mulle_allocator_calloc_t)( size_t, size_t);
typedef void  *(*mulle_allocator_realloc_t)( void *, size_t);
typedef void   (*mulle_allocator_free_t)( void *);


static inline void  *mulle_allocator_malloc( struct mulle_allocator *p, size_t size)
{
   return( (*p->realloc)( NULL, size));
}


static inline void  *mulle_allocator_calloc( struct mulle_allocator *p, size_t n, size_t size)
{
   return( (*p->calloc)( n, size));
}


static inline void  *mulle_allocator_realloc( struct mulle_allocator *p, void *block, size_t size)
{
   return( (*p->realloc)( block, size));
}


static inline void  mulle_allocator_free( struct mulle_allocator *p, void *block)
{
   (*p->free)( block);
}


#endif /* mulle_allocator_h */