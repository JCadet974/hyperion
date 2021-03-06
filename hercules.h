/* HERCULES.H   (c) Copyright Roger Bowler, 1999-2012                */
/*              Hercules Header Files                                */
/*                                                                   */
/*   Released under "The Q Public License Version 1"                 */
/*   (http://www.hercules-390.org/herclic.html) as modifications to  */
/*   Hercules.                                                       */

/* Interpretive Execution - (c) Copyright Jan Jaeger, 1999-2012      */
/* z/Architecture support - (c) Copyright Jan Jaeger, 1999-2012      */

#include "hstdinc.h"        /* Standard header file includes         */

/*-------------------------------------------------------------------*/
/* Performance attribute: use registers to pass function parameters  */
/*     (must be #defined BEFORE "feature,h" since it uses it)        */
/*-------------------------------------------------------------------*/

#if defined(HAVE_ATTR_REGPARM)
  #ifdef _MSVC_
    #define  ATTR_REGPARM(n)   __fastcall
  #else /* GCC presumed */
    #define  ATTR_REGPARM(n)   __attribute__ (( regparm( n )))
  #endif
#else
  #define  ATTR_REGPARM(n)   /* nothing */
#endif

#if defined(HAVE_ATTR_PRINTF)
  /* GCC presumed */
  #define  ATTR_PRINTF(f,v)    __attribute__ (( format( printf, f, v )))
#else
  #define  ATTR_PRINTF(f,v)  /* nothing */
#endif

// -------------------------------------------------------------------
//
//                      PROGRAMMING NOTE
//
//  The "feature.h" header MUST be #included AFTER <config.h> *AND*
//  BEFORE the _HERCULES_H pre-processor variable gets #defined. This
//  is to enure that it is ALWAYS #included regardless of whether the
//  "hercules.h" header has already been #included or not. This is so
//  the various architecture dependent source modules compile properly
//  since they #include themselves several times so as to cause them
//  to be compiled multiple times, each time with a new architecture
//  mode #defined (e.g. 370/390/900). See the very end of the source
//  member "general2.c" for a typical example of this very technique.
//
// -------------------------------------------------------------------
//

//
// Include standard system headers (if not already done)
//

#include "feature.h"      // Hercules [manually maintained] features;
                          // auto-includes featall.h and hostopts.h

                          // ALWAYS include cpuint.h after feature.h
                          // and also assure it is re-included for
                          // each archs.
#include "cpuint.h"

#ifndef _HERCULES_H       // MUST come AFTER "feature.h" is #included
#define _HERCULES_H       // MUST come AFTER "feature.h" is #included

#include "hstdinc.h"      // Precompilation-eligible header files

#ifdef _MSVC_
  #include "getopt.h"
#else
  #if defined(HAVE_GETOPT_LONG) && !defined(__GETOPT_H__)
    #include <getopt.h>
  #endif
#endif

#ifdef OPTION_DYNAMIC_LOAD
  #ifdef HDL_USE_LIBTOOL
    #include <ltdl.h>
  #else
    #if defined(__MINGW__) || defined(_MSVC_)
      #include "w32dl.h"
    #else
      #include <dlfcn.h>
    #endif
  #endif
#endif


///////////////////////////////////////////////////////////////////////
// Private Hercules-specific headers.....
///////////////////////////////////////////////////////////////////////

#include "linklist.h"     // (Hercules-wide linked-list macros)
#include "hconsts.h"      // (Hercules-wide #define constants)
#include "hthreads.h"     // (Hercules-wide threading macros)
#include "hmacros.h"      // (Hercules-wide #define macros)
#include "hmalloc.h"      // (Hercules malloc/free functions)
#include "herror.h"       // (Hercules-wide error definitions)
#include "chain.h"        // (Chain and queue macros/inlines)
#include "extstring.h"    // (Extended string handling routines)

#if !defined(HAVE_BYTESWAP_H) || defined(NO_ASM_BYTESWAP)
 #include "hbyteswp.h"    // (Hercules equivalent of <byteswap.h>)
#endif

#if !defined(HAVE_MEMRCHR)
  #include "memrchr.h"
#endif

#if defined(HAVE_ASSERT_H)
 #include <assert.h>
#endif

#include "hostinfo.h"
#include "version.h"

#include "esa390.h"       // (ESA/390 structure definitions)
#include "hscutl.h"       // (utility functions)
#include "w32util.h"      // (win32 porting functions)
#include "clock.h"        // (TOD definitions)

#include "qeth.h"         // (QETH device definitions)
#include "qdio.h"         // (QDIO instructions, functions, structs)

#include "codepage.h"
#include "logger.h"       // (logmsg, etc)
#include "hdl.h"          // (Hercules Dynamic Loader)

#include "cache.h"

#include "devtype.h"
#include "dasdtab.h"
#include "shared.h"
#include "hetlib.h"
#include "sockdev.h"
#include "w32ctca.h"

#include "service.h"

#include "hsocket.h"
#ifdef _MSVC_
  #include "w32mtio.h"    // 'mtio.h' needed by hstructs.h
  #include "sys/locking.h"
#endif // _MSVC_
#include "hstructs.h"     // (Hercules-wide structures)
#include "hexterns.h"     // (Hercules-wide extern function prototypes)
#include "msgenu.h"       // (Hercules messages)

// Post-process includes
#include "dasdtab.h"
#include "hinlines.h"     // bring Hercules specific inlines here

#endif // _HERCULES_H
