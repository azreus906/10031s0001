/**********************************************************************
 *                                                                    *
 *       system    : 開発演習                                         *
 *       function  : cm_tbad                                          *
 *       designer  : 株式会社セック    2017/11/13                     *
 *                                                                    *
 **********************************************************************/
#include    <stdio.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <sys/ipc.h>
#include    <sys/shm.h>

#define     TSIZE       68608

void    *shmat();

unsigned short  *cm_tbad()
{
    key_t               ikey;           /* "key_t" is  typedef. see includes above.*/
    int                 id;
    unsigned short      *puhtad;

    ikey  = (key_t) getuid();   /* getuid --> see system-call manual */

                                /* shared memory getting (system-call) */
    id = shmget( ikey, TSIZE, IPC_CREAT | 0666 );
    if ( id == -1 )
    {
        perror ( "shmget" );
        return 0;
    }
                                /* shared memory attachment (system-call) */
    puhtad = shmat( id, 0, 0 );
    if ( puhtad == (void *)-1 )
    {
        perror ( "shmat" );
        return 0;
    }

    return puhtad;
}