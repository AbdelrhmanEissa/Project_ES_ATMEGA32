/*
 * p_config.h
 *
 *  Created on: Aug 18, 2024
 *      Author: Abdelrhman M Eissa
 */

#ifndef HAL_PROJECT_FILE_P_CONFIG_H_
#define HAL_PROJECT_FILE_P_CONFIG_H_



/*                  USERS                 */



#define MAX_USERS 10
#define MAX_ATTEMPTS 3
#define MAX_TRIES 3

typedef struct {
    char username[20];
    char password[20];
} User;

User users[MAX_USERS] = {
    {"123", "321"},
    {"456", "654"},
    {"user3", "pass3"},
    {"user4", "pass4"},
    {"user5", "pass5"},
    {"user6", "pass6"},
    {"user7", "pass7"},
    {"user8", "pass8"},
    {"user9", "pass9"},
    {"user10", "pass10"}
};





#define PASSWORD_LENGTH 4
#define USER_LENGTH 4





#endif /* HAL_PROJECT_FILE_P_CONFIG_H_ */
