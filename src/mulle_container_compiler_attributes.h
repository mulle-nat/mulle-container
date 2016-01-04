//
//  mulle_container_compiler_attributes.h
//  mulle-container
//
//  Created by Nat! on 05.11.15.
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

#ifndef mulle_container_attributes__h__
#define mulle_container_attributes__h__

#ifndef mulle_nonnull_first
# define mulle_nonnull_first                __attribute__((nonnull(1)))
# define mulle_nonnull_first_second         __attribute__((nonnull(1,2)))
# define mulle_nonnull_first_second_third   __attribute__((nonnull(1,2,3)))
# define mulle_nonnull_first_second_fourth  __attribute__((nonnull(1,2,4)))
# define mulle_nonnull_first_second_fifth   __attribute__((nonnull(1,2,5)))
# define mulle_nonnull_first_third          __attribute__((nonnull(1,3)))
# define mulle_nonnull_first_third_fourth   __attribute__((nonnull(3,4)))
# define mulle_nonnull_first_fourth         __attribute__((nonnull(1,4)))
# define mulle_nonnull_first_fifth          __attribute__((nonnull(1,5)))
# define mulle_nonnull_second               __attribute__((nonnull(2)))
# define mulle_nonnull_second_third         __attribute__((nonnull(2,3)))
# define mulle_nonnull_third_fourth         __attribute__((nonnull(3,4)))

#endif

#endif /* mulle_container_attributes_h */