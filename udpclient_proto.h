/*
 *  Author : WangBoJing , email : 1989wangbojing@gmail.com
 * 
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of NALEX Inc. (C) 2016
 * 
 *

****       *****
  ***        *
  ***        *                         *               *
  * **       *                         *               *
  * **       *                         *               *
  *  **      *                        **              **
  *  **      *                       ***             ***
  *   **     *       ******       ***********     ***********    *****    *****
  *   **     *     **     **          **              **           **      **
  *    **    *    **       **         **              **           **      *
  *    **    *    **       **         **              **            *      *
  *     **   *    **       **         **              **            **     *
  *     **   *            ***         **              **             *    *
  *      **  *       ***** **         **              **             **   *
  *      **  *     ***     **         **              **             **   *
  *       ** *    **       **         **              **              *  *
  *       ** *   **        **         **              **              ** *
  *        ***   **        **         **              **               * *
  *        ***   **        **         **     *        **     *         **
  *         **   **        **  *      **     *        **     *         **
  *         **    **     ****  *       **   *          **   *          *
*****        *     ******   ***         ****            ****           *
                                                                       *
                                                                      *
                                                                  *****
                                                                  ****

 *
 *
 */





#ifndef __NATTY_PROTOCOL_H__
#define __NATTY_PROTOCOL_H__

/* ** **** ********  ****************  Length  ****************  ******** **** ** */
#define NTY_DEVID_LENGTH				4
#define NTY_ACKNUM_LENGTH				4
#define NTY_IPADDR_LENGTH				4
#define NTY_IPPORT_LENGTH				2

#define NTY_HEARTBEAT_ACK_LENGTH		5
#define NTY_LOGOUT_ACK_LENGTH			5
#define NTY_LOGIN_ACK_LENGTH			512
#define NTY_P2PADDR_ACK_LENGTH			512
#define NTY_P2P_NOTIFY_ACK_LENGTH		128

/* ** **** ********  ****************  Index  ****************  ******** **** ** */
#define NEY_PROTO_VERSION_IDX					0
#define NTY_PROTO_TYPE_IDX						(NEY_PROTO_VERSION_IDX+1)

#define NTY_PROTO_LOGIN_REQ_DEVID_IDX					(NTY_PROTO_TYPE_IDX+1)	
#define NTY_PROTO_LOGIN_REQ_ACKNUM_IDX				(NTY_PROTO_LOGIN_REQ_DEVID_IDX+NTY_DEVID_LENGTH)
#define NTY_PROTO_LOGIN_REQ_CRC_IDX					(NTY_PROTO_LOGIN_REQ_ACKNUM_IDX+NTY_ACKNUM_LENGTH)

#define NTY_PROTO_LOGIN_ACK_ACKNUM_IDX					(NTY_PROTO_TYPE_IDX+1)
#define NTY_PROTO_LOGIN_ACK_FRIENDS_COUNT_IDX			(NTY_PROTO_LOGIN_ACK_ACKNUM_IDX+NTY_ACKNUM_LENGTH)
#define NTY_PROTO_LOGIN_ACK_FRIENDSLIST_START_IDX		(NTY_PROTO_LOGIN_ACK_FRIENDS_COUNT_IDX+2)

#define NTY_PROTO_LOGIN_ACK_FRIENDSLIST_DEVID_IDX(x)								\
					(NTY_PROTO_LOGIN_ACK_FRIENDSLIST_START_IDX + 					\
					(NTY_DEVID_LENGTH+NTY_IPADDR_LENGTH+NTY_IPPORT_LENGTH)*(x))
					
#define NTY_PROTO_LOGIN_ACK_FRIENDSLIST_ADDR_IDX(x)								\
					(NTY_PROTO_LOGIN_ACK_FRIENDSLIST_START_IDX + NTY_DEVID_LENGTH +	\
					(NTY_DEVID_LENGTH+NTY_IPADDR_LENGTH+NTY_IPPORT_LENGTH)*(x))

#define NTY_PROTO_LOGIN_ACK_FRIENDSLIST_PORT_IDX(x)								\
					(NTY_PROTO_LOGIN_ACK_FRIENDSLIST_START_IDX + NTY_DEVID_LENGTH + NTY_IPADDR_LENGTH +	\
					(NTY_DEVID_LENGTH+NTY_IPADDR_LENGTH+NTY_IPPORT_LENGTH)*(x))

#define NTY_PROTO_LOGIN_ACK_CRC_IDX(x)		(NTY_PROTO_LOGIN_ACK_FRIENDSLIST_PORT_IDX(x)+NTY_IPPORT_LENGTH)


#define NTY_PROTO_HEARTBEAT_DEVID_IDX		NTY_PROTO_LOGIN_REQ_DEVID_IDX
#define NTY_PROTO_HEARTBEAT_ACKNUM_IDX		NTY_PROTO_LOGIN_REQ_ACKNUM_IDX


#define NTY_PROTO_P2PADDR_REQ_DEVID_IDX		(NTY_PROTO_TYPE_IDX+1)
#define NTY_PROTO_P2PADDR_REQ_ACKNUM_IDX	(NTY_PROTO_P2PADDR_REQ_DEVID_IDX+NTY_DEVID_LENGTH)

#define NTY_PROTO_P2PADDR_REQ_FRIENDS_COUNT_IDX	(NTY_PROTO_P2PADDR_REQ_ACKNUM_IDX+NTY_ACKNUM_LENGTH)
#define NTY_PROTO_P2PADDR_REQ_FRIENDSLIST_START_IDX	(NTY_PROTO_P2PADDR_REQ_FRIENDS_COUNT_IDX+2)

#define NTY_PROTO_P2PADDR_REQ_FRIENDS_DEVID_IDX(x) (NTY_PROTO_P2PADDR_REQ_FRIENDSLIST_START_IDX + NTY_DEVID_LENGTH*(x))	

#define NTY_PROTO_P2PADDR_ACK_ACKNUM_IDX	NTY_PROTO_LOGIN_ACK_ACKNUM_IDX
#define NTY_PROTO_P2PADDR_ACK_FRIENDS_COUNT_IDX		NTY_PROTO_LOGIN_ACK_FRIENDS_COUNT_IDX

#define NTY_PROTO_P2PADDR_ACK_FRIENDSLIST_START_IDX	NTY_PROTO_LOGIN_ACK_FRIENDSLIST_START_IDX
#define NTY_PROTO_P2PADDR_ACK_FRIENDSLIST_DEVID_IDX(x)	NTY_PROTO_LOGIN_ACK_FRIENDSLIST_DEVID_IDX(x)

#define NTY_PROTO_P2PADDR_ACK_FRIENDSLIST_ADDR_IDX(x)	NTY_PROTO_LOGIN_ACK_FRIENDSLIST_ADDR_IDX(x)
#define NTY_PROTO_P2PADDR_ACK_FRIENDSLIST_PORT_IDX(x)	NTY_PROTO_LOGIN_ACK_FRIENDSLIST_PORT_IDX(x)

#define NTY_PROTO_P2PADDR_ACK_CRC_IDX(x)			NTY_PROTO_LOGIN_ACK_CRC_IDX(x)

#define NTY_PROTO_P2P_NOTIFY_DEVID_IDX				NTY_PROTO_HEARTBEAT_DEVID_IDX
#define NTY_PROTO_P2P_NOTIFY_ACKNUM_IDX				NTY_PROTO_HEARTBEAT_ACKNUM_IDX
#define NTY_PROTO_P2P_NOTIFY_IPADDR_IDX				(NTY_PROTO_P2P_NOTIFY_ACKNUM_IDX+NTY_ACKNUM_LENGTH)
#define NTY_PROTO_P2P_NOTIFY_IPPORT_IDX				(NTY_PROTO_P2P_NOTIFY_IPADDR_IDX+NTY_IPADDR_LENGTH)
#define NTY_PROTO_P2P_NOTIFY_CRC_IDX				(NTY_PROTO_P2P_NOTIFY_IPPORT_IDX+NTY_IPPORT_LENGTH)


#define NTY_PROTO_DATAPACKET_DEVID_IDX				NTY_PROTO_HEARTBEAT_DEVID_IDX
#define NTY_PROTO_DATAPACKET_ACKNUM_IDX				NTY_PROTO_HEARTBEAT_ACKNUM_IDX
#define NTY_PROTO_DATAPACKET_RECE_COUNT_IDX			(NTY_PROTO_DATAPACKET_ACKNUM_IDX+NTY_ACKNUM_LENGTH)
#define NTY_PROTO_DATAPACKET_RECE_IDX(x)			(NTY_PROTO_DATAPACKET_RECE_COUNT_IDX + 2 + NTY_DEVID_LENGTH*(x))

#define NTY_PROTO_DATAPACKET_CONTENT_COUNT_IDX(x)		NTY_PROTO_DATAPACKET_RECE_IDX(x)
#define NTY_PROTO_DATAPACKET_CONTENT_IDX(x)			(NTY_PROTO_DATAPACKET_CONTENT_COUNT_IDX(x)+2)

#define NTY_PROTO_DATAPACKET_NOTIFY_DEVID_IDX		NTY_PROTO_HEARTBEAT_DEVID_IDX
#define NTY_PROTO_DATAPACKET_NOTIFY_ACKNUM_IDX		NTY_PROTO_HEARTBEAT_ACKNUM_IDX
#define NTY_PROTO_DATAPACKET_NOTIFY_SRC_DEVID_IDX	(NTY_PROTO_DATAPACKET_NOTIFY_ACKNUM_IDX+NTY_ACKNUM_LENGTH)
#define NTY_PROTO_DATAPACKET_NOTIFY_CONTENT_COUNT_IDX		(NTY_PROTO_DATAPACKET_NOTIFY_SRC_DEVID_IDX+NTY_DEVID_LENGTH)
#define NTY_PROTO_DATAPACKET_NOTIFY_CONTENT_IDX		(NTY_PROTO_DATAPACKET_NOTIFY_CONTENT_COUNT_IDX+4)

#define NTY_PROTO_DATAPACKET_ACK_DEVID_IDX		NTY_PROTO_HEARTBEAT_DEVID_IDX
#define NTY_PROTO_DATAPACKET_ACK_ACKNUM_IDX		NTY_PROTO_HEARTBEAT_ACKNUM_IDX
#define NTY_PROTO_DATAPACKET_ACK_SRC_DEVID_IDX	(NTY_PROTO_DATAPACKET_ACK_ACKNUM_IDX+NTY_ACKNUM_LENGTH)
#define NTY_PROTO_DATAPACKET_ACK_CRC_IDX		(NTY_PROTO_DATAPACKET_ACK_SRC_DEVID_IDX+NTY_DEVID_LENGTH)


/* ** **** ********  ****************  Header  ****************  ******** **** ** */
#define NTY_PROTO_LOGIN_REQ			0x01
#define NTY_PROTO_LOGIN_ACK			0x81

#define NTY_PROTO_HEARTBEAT_REQ		0x02 //'H'
#define NTY_PROTO_HEARTBEAT_ACK		0x82

#define NTY_PROTO_LOGOUT_REQ		0x03
#define NTY_PROTO_LOGOUT_ACK		0x83



#define NTY_PROTO_P2P_ADDR_REQ			0x11
#define NTY_PROTO_P2P_ADDR_ACK			0x91

#define NTY_PROTO_P2P_NOTIFY_REQ			0x12 //server sendto client
#define NTY_PROTO_P2P_NOTIFY_ACK			0x92


#define NTY_PROTO_P2P_CONNECT_REQ			0x13 //use for client ,
#define NTY_PROTO_P2P_CONNECT_ACK			0x93 //use for client ,

#define NTY_PROTO_DATAPACKET_REQ			0x21 //use for client ,
#define NTY_PROTO_DATAPACKET_ACK			0xA1 //use for client ,

#define NTY_PROTO_DATAPACKET_NOTIFY_REQ			0x22 //use for client ,
#define NTY_PROTO_DATAPACKET_NOTIFY_ACK			0xA2 //use for client ,

#define NTY_PROTO_DATAPACKET_CONTENT_COUNT_IDX(x)		NTY_PROTO_DATAPACKET_RECE_IDX(x)
//#define NTY_PROTO_DATAPACKET_CONTENT_IDX(x)			(NTY_PROTO_DATAPACKET_CONTENT_COUNT_IDX(x)+2)


typedef unsigned int U32;
typedef unsigned short U16;
typedef unsigned char U8;

typedef struct _ClientInfo {
	U8 isEnable;
	U16 port;
	U32 addr;
	U32 devId;
} ClientInfo;



#endif

