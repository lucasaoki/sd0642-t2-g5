/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "../include/pw2.h"
#include "../include/svrInclude.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
pw2_query_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		char *query_1_arg;
	} argument;
	union {
		char *query_1_res;
	} result;
	bool_t retval;
	xdrproc_t _xdr_argument, _xdr_result;
	bool_t (*local)(char *, void *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case QUERY:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (bool_t (*) (char *, void *,  struct svc_req *))query_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	retval = (bool_t) (*local)((char *)&argument, (void *)&result, rqstp);
	if (retval > 0 && !svc_sendreply(transp, (xdrproc_t) _xdr_result, (char *)&result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if (!pw2_query_prog_1_freeresult (transp, _xdr_result, (caddr_t) &result))
		fprintf (stderr, "%s", "unable to free results");

	return;
}

int initializeMySQL(MYSQL *mysql){
	
	if( !mysql_init(mysql) ){
		return -1;
	}
 	
 	if( mysql_real_connect(mysql,"localhost","grupo05sd","06e728","grupo05sd",0,NULL,0) == NULL){	
 	//if( mysql_real_connect(mysql,"localhost","gilvolpe","gil*data*base","testeSD",0,NULL,0) == NULL){
		return -1;
	}
}

extern MYSQL mysql;

int
main (int argc, char **argv)
{
	
	initializeMySQL(&mysql);

	register SVCXPRT *transp;

	pmap_unset (PW2_QUERY_PROG, QUERY);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, PW2_QUERY_PROG, QUERY, pw2_query_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (PW2_QUERY_PROG, QUERY, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, PW2_QUERY_PROG, QUERY, pw2_query_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (PW2_QUERY_PROG, QUERY, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
