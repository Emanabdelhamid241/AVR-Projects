
#include "main.h"
/**************************************************************************************************/
int main(void){
	u8 Local_u8_Key,Local_u8_Counter=0;
	u8 spass[]=pass;
	u8 Local_u8_index_input ;
u8 try_check=0;

	            DIO_voidInit();
				LCD_enum_INIT();
				KPD_enum_Init();
				DC_MOTOR_enum_INIT();
				LCD_enum_GO_TO_XY(LCD_u8_LINE1,0);
								LCD_enum_Send_String("Enter Password");
								_delay_ms(1000);
									LCD_enum_Clear ();


	while(1){
       	KPD_enum_Get_Key_State(&Local_u8_Key);
/*is there is no keys pressed*/
	/*no displaying on LCD*/
	if(Local_u8_Key != KPD_u8_Keys_NO_Pressed  ){
         LCD_enum_Send_char('*');

         Local_u8_input[Local_u8_index_input] = Local_u8_Key;
         Local_u8_index_input++;
         Local_u8_Counter++;
	}
    	 if (Local_u8_Counter == len) {
    		 for(Local_u8_index_input =0 ;Local_u8_index_input<=len ; Local_u8_index_input++){
    		 				if(Local_u8_input[Local_u8_index_input] == spass[Local_u8_index_input]){
    		 					LCD_enum_GO_TO_XY(LCD_u8_LINE1,0);
    		 					 LCD_enum_Send_String ("Correct Password");
    		 					_delay_ms(1000);
    		 				 LCD_enum_Clear ();
    		 				motor_option();
    		 				 break;
    		 				}
    		 				else{
    		 								LCD_enum_GO_TO_XY(LCD_u8_LINE1,0);
    		 				    			 LCD_enum_Send_String ("wrong Password,");
    		 				    			 LCD_enum_GO_TO_XY(2,0);
    		 				    			LCD_enum_Send_String ("please try again");
    		 				    			_delay_ms(1000);
    		 				    			LCD_enum_Clear ();
    		 				    			main();
    		 				    			try_check++;

    		 				    				     	 if(try_check==MAX_try_check){
    		 				    				   		  LCD_enum_Clear ();
    		 		  	 	       		       			 LCD_enum_Send_String ("please try again after 1 min");
		    		     	 			      			 _delay_ms(60000);
    		 			   	 			      			LCD_enum_Clear ();
    		 			   	 			      		try_check=0;
     				     	 		    				  break;
    		 				    				     	 	}
    		 				    				     	 else{
    		 				    				     	 }

    		 				    			}



    		                      }

                 }

    	 }

    	 return 0;
    	 	}


/***************************************************************************************************/
void motor_option(){

u8 option;
                                        LCD_enum_Clear();
                                        LCD_enum_GO_TO_XY(LCD_u8_LINE1,0);
    		                		    LCD_enum_Send_String ("1-DC ");
    		                		    LCD_enum_GO_TO_XY (2 , 0);
    		                		    LCD_enum_Send_String ("2-STEPPER ");
    		                		    LCD_enum_GO_TO_XY (1 , 6);
    		                		     LCD_enum_Send_String ("3-SERVO ");
    		                		    while(1){
    		                		    	KPD_enum_Get_Key_State(&option);
    		                		    			if (option != KPD_u8_Keys_NO_Pressed) {
    		                		    				if (option == '1') {
    		                		    					LCD_enum_Clear ();
    		                		    					DC_MOTOR_void_direction() ;
    		                		    					break;
    		                		    				} else if (option == '2') {
    		                		    					LCD_enum_Clear ();
      		                		    					stepper_MOTOR_void_direction();
    		                		    					break;
    		                		    				}
    		                		    				 else if (option == '3') {
    		                    		    					LCD_enum_Clear ();
    		                    		    					choice_angle_servo();
    		     	                		    					break;
    		                		    				    		                		    				}

    		                		    }
    		                		    }
}
/****************************************************************************************************************/
void stepper_MOTOR_void_direction() {
//	u8 stepper_direction;

	                                      LCD_enum_Clear ();
	    		                		   	LCD_enum_GO_TO_XY (1 , 0);
	    		                	    LCD_enum_Send_String ("1-CW");
	    		               	   		 LCD_enum_GO_TO_XY (1 , 5);
	    		                	   	    LCD_enum_Send_String ("2-CCW");
	    		                	   	 LCD_enum_GO_TO_XY (2 , 0);
	    		                	   	 	LCD_enum_Send_String ("3-STOP");

	while (1) {

		KPD_enum_Get_Key_State(&stepper_direction);
		if (stepper_direction != KPD_u8_Keys_NO_Pressed) {
			if (stepper_direction == '1') {
				LCD_enum_Clear ();
				Stepper_motor_enum_INIT ();
				stepper_direction=CW;
				choice_angle_stepper();

				break;
			} else if (stepper_direction == '2') {
				LCD_enum_Clear ();
				Stepper_motor_enum_INIT ();
				stepper_direction=CCW;
				choice_angle_stepper();

				break;
			}
			else if (stepper_direction == '3') {
							LCD_enum_Clear ();
							Stepper_motor_enum_STOP ();
							break;
						}

		}
	}
}
/*****************************************************************************************************/
void DC_MOTOR_void_direction(void)
{
	DC_MOTOR_enum_INIT();
	u8 direction;
	LCD_enum_Clear();
	LCD_enum_GO_TO_XY(LCD_u8_LINE1, 0);
	LCD_enum_Send_String("1-CW");

	LCD_enum_GO_TO_XY(LCD_u8_LINE1, 5);
	LCD_enum_Send_String("2-CCW");

	LCD_enum_GO_TO_XY (2 , 0);
	LCD_enum_Send_String ("3-STOP");

	while (1) {
		KPD_enum_Get_Key_State(&direction);
		if (direction != KPD_u8_Keys_NO_Pressed) {
			if (direction == '1') {
				LCD_enum_Clear ();
				DC_MOTOR_enum_Start(CW);
				break;
			} else if (direction == '2') {
				LCD_enum_Clear ();
				DC_MOTOR_enum_Start(CCW);
				break;
			}
			else if(direction=='3'){
				LCD_enum_Clear ();
				DC_MOTOR_enum_Stop();
				break;

			}
		}
	}
}
/********************************************************************************************************/
void choice_angle_stepper(){
	u8 angle;
		LCD_enum_Clear();
		LCD_enum_GO_TO_XY(LCD_u8_LINE1, 0);
		LCD_enum_Send_String("1-90");

		LCD_enum_GO_TO_XY(LCD_u8_LINE1, 7);
		LCD_enum_Send_String("2-180");

		LCD_enum_GO_TO_XY (2 , 0);
		LCD_enum_Send_String ("3-270");

		LCD_enum_GO_TO_XY (2 , 7);
		LCD_enum_Send_String ("4-360");


		while (1) {
			KPD_enum_Get_Key_State(&angle);
			if (angle != KPD_u8_Keys_NO_Pressed) {
				if (angle == '1') {
					Stepper_motor_enum_INIT();
					Stepper_moter_enum_Move(stepper_direction,90);
//					break;
				} else if (angle == '2') {
					Stepper_motor_enum_INIT();
					Stepper_moter_enum_Move(stepper_direction,180);
//					break;
				}
				else if(angle=='3'){
					Stepper_motor_enum_INIT();
					Stepper_moter_enum_Move(stepper_direction,270);
//					break;

				}
				else if(angle=='4'){
				Stepper_motor_enum_INIT();
				Stepper_moter_enum_Move(stepper_direction,360);
//				break;

								}
			}
		}
}


/********************************************************************************************************/
void choice_angle_servo(){
	u8 angleS=0;
	SERVO_motor_enum_INIT();

			LCD_enum_Clear();
			LCD_enum_GO_TO_XY(LCD_u8_LINE1, 0);
			LCD_enum_Send_String("1-45");

			LCD_enum_GO_TO_XY(LCD_u8_LINE1, 7);
			LCD_enum_Send_String("2-60");

			LCD_enum_GO_TO_XY (2 , 0);
			LCD_enum_Send_String ("3-90");

			LCD_enum_GO_TO_XY (2 , 7);
			LCD_enum_Send_String ("4-180");


			while (1) {
				KPD_enum_Get_Key_State(&angleS);
				if (angleS != KPD_u8_Keys_NO_Pressed) {
					if (angleS == '1') {
						LCD_enum_Clear();
 						SERVO_MOTOR_enum_SET_Servo_Motor_Angle(45);
						break;
					} else if (angleS == '2') {
						LCD_enum_Clear();
						SERVO_MOTOR_enum_SET_Servo_Motor_Angle(60);
						break;
					}
					else if(angleS=='3'){
						LCD_enum_Clear();
						SERVO_MOTOR_enum_SET_Servo_Motor_Angle(90);
						break;

					}
					else if(angleS=='4'){
						SERVO_MOTOR_enum_SET_Servo_Motor_Angle(180);
						break;

									}
				}
			}

}
