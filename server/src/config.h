#ifndef _CONFIG_H_
#define _CONFIG_H_

#ifdef __GNUC__
#	define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#	define UNUSED(x) UNUSED_ ## x
#endif

#ifdef NP_SSH
#	include <libnetconf_ssh.h>
#	include "./ssh/server_ssh.h"
#	include "./ssh/cfgnetopeer_transapi_ssh.h"
#	include "./ssh/netconf_server_transapi_ssh.h"
#endif

#ifdef NP_TLS
#	include <libnetconf_tls.h>
#	include "./tls/server_tls.h"
#	include "./tls/cfgnetopeer_transapi_tls.h"
#	include "./tls/netconf_server_transapi_tls.h"
#endif

#ifndef MODULES_CFG_DIR
#	define MODULES_CFG_DIR "/etc/netopeer/modules.conf.d/"
#endif

/* maximal value from the sizes of specific client implementations */
#define CLIENT_STRUCT_MAX_SIZE sizeof(struct client_struct_ssh)

/* the initial size of the reading buffer */
#define BASE_READ_BUFFER_SIZE 2048

/* end tags of NETCONF messages */
#define NC_V10_END_MSG "]]>]]>"
#define NC_V11_END_MSG "\n##\n"

/* environment variable with verbose level */
#define ENVIRONMENT_VERBOSE "NETOPEER_VERBOSE"

/* names of the 2 base netopeer static transapi modules */
#define NETOPEER_MODULE_NAME "Netopeer"
#define NCSERVER_MODULE_NAME "NETCONF-server"

/* every number-of-secs will the last sent or received data timestamp be checked */
#define CALLHOME_PERIODIC_LINGER_CHECK 5

#endif /* _CONFIG_H_ */
