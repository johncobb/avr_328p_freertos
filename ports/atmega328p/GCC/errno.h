/* errno.h standard header */
#ifndef _ERRNO
#define _ERRNO




/* ERROR CODES */
#define EDOM    _EDOM
#define ERANGE  _ERANGE
#define EFPOS   _EFPOS
#define EILSEQ  _EILSEQ

               /* lwip error codes, from cygwin errno.h */
#define EIO 5		      /* I/O error */
#define EWOULDBLOCK 11          /* Operation would block */
#define ENOMEM 12	      /* Not enough core */
#define EFAULT 14	                        /* Bad address */
#define EINVAL 22	                        /* Invalid argument */
#define ENOSYS 88                         /* Function not implemented */
#define ECONNRESET 104            /* Connection reset by peer */
#define ENOBUFS 105	     /* No buffer space available */
#define ENOPROTOOPT 109	     /* Protocol not available */
#define ESHUTDOWN 110	     /* Can't send after socket shutdown */
#define EADDRINUSE 112	     /* Address already in use */
#define ECONNABORTED 113     /* Connection aborted */
#define EHOSTUNREACH 118	     /* Host is unreachable */
#define ENOTCONN 128	     /* Socket is not connected */

#define _NERR   129   /* one more than last code */





#endif
