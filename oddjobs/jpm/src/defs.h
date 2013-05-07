/* Author: Danny Hadley
 * Date: Spring 2013
*/
#ifndef _DEFS_H
#define _DEFS_H

#define JPM_ERR_NOARG "you need to specify a command.\n" JPM_HELP
#define JPM_ERR_NOREADY "not enough information was provided\n" JPM_HELP
#define JPM_WELCOME "welcome to jpm"
#define JPM_HELP "jpm help:" JPM_COMMANDS

#define JPM_C_COMPILE "  compile: runs the scripts compiler\n"
#define JPM_C_UPLOAD "  upload: uploads the script to the server\n"
#define JPM_C_INIT "  init: creates the starting files for the package. run once\n"
#define JPM_COMMANDS "\n" JPM_C_COMPILE JPM_C_UPLOAD JPM_C_INIT

#endif