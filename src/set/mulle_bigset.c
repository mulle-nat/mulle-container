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
#include "mulle_bigset.h"
#include "mulle_container_callback.h"


void   mulle_bigset_init( struct mulle_bigset *set,
                       size_t capacity,
                       struct mulle_container_keycallback *callback,
                       struct mulle_allocator *allocator)
{
   _mulle_bigset_init( (struct _mulle_bigset *) set, capacity, callback, allocator);

   set->_callback  = callback;
   set->_allocator = allocator;
}


struct mulle_bigset   *mulle_bigset_create( size_t capacity,
                                      struct mulle_container_keycallback *callback,
                                      struct mulle_allocator *allocator)
{
   struct mulle_bigset *set;
   
   if( ! allocator)
      allocator = &mulle_default_allocator;
   
   set = mulle_allocator_malloc( allocator, sizeof( struct mulle_bigset));
   if( set)
      mulle_bigset_init( set, capacity, callback, allocator);
   return( set);
}
