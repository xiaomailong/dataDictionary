#ifndef NESTINGMARK_Radio_Message_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session
#define NESTINGMARK_Radio_Message_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session
/* =============================================================================
Formalization of Subset-026-8 (Chapter 8: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_Acknowledgement_of_termination_of_a_communication_session
- Description: UNISIG SUBSET-026-8, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) Siemens AG, 2014, All Rights Reserved
 	
- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): SiemensRailAutomation

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.  	
============================================================================= */
#include <stdint.h>
#include "opnETCS_Variables.h"



struct DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
// Packet Number = 39

	uint32_t NID_MESSAGE;                     		// # 8		// int
	uint32_t               L_MESSAGE             ;		// # 10		// int
	uint32_t               T_TRAIN               ;		// # 32		// float
	T_m_ack                M_ACK                 ;		// # 1	
	uint32_t               NID_LRBG              ;		// # 24		// int
} 


   Message[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session T_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session;
// typ -> ptrtyp
typedef  T_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session* TP_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session;
// declaration of variable of ptrtyp
extern TP_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session  Radio_Packet_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session  Radio_Packet_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session = new(T_DATA_Radio_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session);
// and now fill in the content to start with ...
// Access variable like this: Radio_Packet_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session->...
// maybe : memset(Radio_Packet_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session, 0, sizeof(T_DATA_Radio_Packet_TrackToTrain_Acknowledgement_of_termination_of_a_communication_session));
// for complete 0 content.

#endif


