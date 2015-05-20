allocation_tracker enables callers to detect possible memory leaks in a cross platform way.
Note that some macros are not c++ standardized but most modern compilers support them.
See AllocationTrackerExample for usage. The code including the allocation_tracker.h file must be compiled with c++11 compiler or compiler supporting higher version
of c++14. Also the macro TRACK_MEMORY needs to be defined to including memory tracking. 
