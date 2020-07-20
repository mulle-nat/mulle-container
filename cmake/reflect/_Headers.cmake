#
# cmake/reflect/_Headers.cmake is generated by `mulle-sde reflect`. Edits will be lost.
#
if( MULLE_TRACE_INCLUDE)
   MESSAGE( STATUS "# Include \"${CMAKE_CURRENT_LIST_FILE}\"" )
endif()

set( INCLUDE_DIRS
src
src/array
src/array/pointer
src/array/pointerpair
src/array/struct
src/array/uniquepointer
src/farmhash
src/hash
src/map
src/map/pointer
src/queue
src/range
src/rangeset
src/reflect
src/set
src/set/pointer
)

set( PRIVATE_GENERATED_HEADERS
src/reflect/_mulle-container-include-private.h
)

set( PRIVATE_HEADERS
src/farmhash/farmhash.h
src/farmhash/largeint.h
src/include-private.h
)

set( PUBLIC_GENERATED_HEADERS
src/reflect/_mulle-container-include.h
)

set( PUBLIC_HEADERS
src/array/mulle--array.h
src/array/mulle-array.h
src/array/mulle--structarray.h
src/array/pointer/mulle--pointerarray.h
src/array/pointer/mulle-pointerarray.h
src/array/pointerpair/mulle--pointerpairarray.h
src/array/pointerpair/mulle-pointerpairarray.h
src/array/pointerpair/mulle-pointerpair.h
src/array/struct/mulle-structarray.h
src/array/uniquepointer/mulle--uniquepointerarray.h
src/array/uniquepointer/mulle-uniquepointerarray.h
src/hash/mulle-hash.h
src/hash/mulle-prime.h
src/include.h
src/map/mulle--map.h
src/map/mulle-map.h
src/map/pointer/mulle--pointermap.h
src/mulle-container-callback-global.h
src/mulle-container-callback.h
src/mulle-container-compiler-attributes.h
src/mulle-container.h
src/mulle-container-math.h
src/mulle-container-operation.h
src/queue/mulle--pointerqueue.h
src/range/mulle-range.h
src/rangeset/mulle--rangeset.h
src/set/mulle--set.h
src/set/mulle-set.h
src/set/pointer/mulle--pointerset-generic.h
src/set/pointer/mulle--pointerset.h
src/set/pointer/mulle--pointerset-struct.h
)

