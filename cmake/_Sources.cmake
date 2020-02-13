#
# cmake/_Sources.cmake is generated by `mulle-sde`. Edits will be lost.
#
if( MULLE_TRACE_INCLUDE)
   MESSAGE( STATUS "# Include \"${CMAKE_CURRENT_LIST_FILE}\"" )
endif()

set( SOURCES
src/array/mulle--array.c
src/array/mulle-array.c
src/array/mulle-pointerarray.c
src/array/mulle-pointerpairarray.c
src/farmhash/farmhash.c
src/hash/mulle-hash.c
src/hash/mulle-prime.c
src/map/mulle--map.c
src/map/mulle-map.c
src/map/mulle--pointermap.c
src/mulle-container-callback.c
src/queue/mulle--pointerqueue.c
src/range/mulle-range.c
src/rangeset/mulle--rangeset.c
src/set/mulle-pointerset.c
src/set/mulle--set.c
src/set/mulle-set.c
)
