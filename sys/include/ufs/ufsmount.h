/*-
 * Copyright (c) 1982, 1986, 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)ufsmount.h	8.6 (Berkeley) 3/30/95
 * $FreeBSD$
 */

#ifdef MALLOC_DECLARE
MALLOC_DECLARE(M_UFSMNT);
#endif

typedef struct Buf Buf;
typedef struct Fs Fs;
typedef struct inode inode;
struct nameidata;
struct taskqueue;
struct timeval;
typedef struct Ucred Ucred;
struct uio;
struct vnode;
struct ufs_extattr_per_mount;
struct jblocks;
struct inodedep;
struct MountPoint;

//TAILQ_HEAD(inodedeplst, inodedep);
//LIST_HEAD(bmsafemaphd, bmsafemap);

/* This structure describes the UFS specific mount structure data. */
// TODO HARVEY Maybe combine this with MountPoint?
typedef struct ufsmount {
	MountPoint	*um_mountp;			/* filesystem vfs structure */
	//struct	cdev *um_dev;			/* device mounted */
	//struct	g_consumer *um_cp;
	//struct	bufobj *um_bo;			/* Buffer cache object */
	//struct	vnode *um_devvp;		/* block device mounted vnode */
	uint64_t	um_fstype;			/* type of filesystem */
	Fs		*um_fs;				/* pointer to superblock */
	//struct	ufs_extattr_per_mount um_extattr;	/* extended attrs */
	uint64_t	um_nindir;			/* indirect ptrs per block */
	uint64_t	um_bptrtodb;			/* indir ptr to disk block */
	uint64_t	um_seqinc;			/* inc between seq blocks */
	QLock um_lock;					/* Protects ufsmount & fs */
	//pid_t	um_fsckpid;			/* PID permitted fsck sysctls */
	//struct	mount_softdeps *um_softdep;	/* softdep mgmt structure */
	//struct	vnode *um_quotas[MAXQUOTAS];	/* pointer to quota files */
	//struct	ucred *um_cred[MAXQUOTAS];	/* quota file access cred */
	//time_t	um_btime[MAXQUOTAS];		/* block quota time limit */
	//time_t	um_itime[MAXQUOTAS];		/* inode quota time limit */
	//char	um_qflags[MAXQUOTAS];		/* quota specific flags */
	int64_t	um_savedmaxfilesize;		/* XXX - limit maxfilesize */
	//int	um_candelete;			/* devvp supports TRIM */
	//int	um_writesuspended;		/* suspension in progress */
	//uint	um_trim_inflight;
	//struct taskqueue *um_trim_tq;
	int	(*um_balloc)(vnode *, off_t, int, Ucred *, int, Buf **);
	int	(*um_blkatoff)(vnode *, off_t, char **, void **);
	int	(*um_truncate)(vnode *, off_t, int, Ucred *);
	int	(*um_update)(vnode *, int);
	int	(*um_valloc)(vnode *, int, Ucred *, vnode **);
	int	(*um_vfree)(vnode *, ino_t, int);
	void	(*um_ifree)(ufsmount *, inode *);
	int	(*um_rdonly)(inode *);
	void	(*um_snapgone)(inode *);
} ufsmount;

/*#define	UFS_BALLOC(aa, bb, cc, dd, ee, ff) VFSTOUFS((aa)->v_mount)->um_balloc(aa, bb, cc, dd, ee, ff)
#define	UFS_BLKATOFF(aa, bb, cc, dd) VFSTOUFS((aa)->v_mount)->um_blkatoff(aa, bb, cc, dd)
#define	UFS_TRUNCATE(aa, bb, cc, dd) VFSTOUFS((aa)->v_mount)->um_truncate(aa, bb, cc, dd)
#define	UFS_UPDATE(aa, bb) VFSTOUFS((aa)->v_mount)->um_update(aa, bb)
#define	UFS_VALLOC(aa, bb, cc, dd) VFSTOUFS((aa)->v_mount)->um_valloc(aa, bb, cc, dd)
#define	UFS_VFREE(aa, bb, cc) VFSTOUFS((aa)->v_mount)->um_vfree(aa, bb, cc)
#define	UFS_IFREE(aa, bb) ((aa)->um_ifree(aa, bb))
#define	UFS_RDONLY(aa) (ITOUMP(aa)->um_rdonly(aa))
#define	UFS_SNAPGONE(aa) (ITOUMP(aa)->um_snapgone(aa))

#define	UFS_LOCK(aa)	mtx_lock(&(aa)->um_lock)
#define	UFS_UNLOCK(aa)	mtx_unlock(&(aa)->um_lock)
#define	UFS_MTX(aa)	(&(aa)->um_lock)
*/
/*
 * Filesystem types
 */
#define	UFS1	1
#define	UFS2	2

/*
 * Flags describing the state of quotas.
 */
#define	QTF_OPENING	0x01			/* Q_QUOTAON in progress */
#define	QTF_CLOSING	0x02			/* Q_QUOTAOFF in progress */
#define	QTF_64BIT	0x04			/* 64-bit quota file */

/*
 * Macros to access filesystem parameters in the ufsmount structure.
 * Used by ufs_bmap.
 */
#define	blkptrtodb(ump, b)		((b) << (ump)->um_bptrtodb)
#define	is_sequential(ump, a, b)	((b) == (a) + ump->um_seqinc)
