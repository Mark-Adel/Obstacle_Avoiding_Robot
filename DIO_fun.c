
# include "STD_TYPES.h"
# include "BIT_MATH.h"
#include "Dio_reg.h"
#include "Dio_interface.h"

void DIO_U8TogelPin(u8 Copy_u8PortId,u8 Copy_u8PinId)
{  u8 x;
	 x=DIO_u8GetPinValue(Copy_u8PortId,Copy_u8PinId);
	 x=x^0xfe;
	 DIO_voidSetPinValue(Copy_u8PortId,Copy_u8PinId,  x);

}


 void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId, u8 Copy_u8PinDir)
	{


		if(Copy_u8PinDir==DIO_u8OUTPUT)
		  {
		   switch (Copy_u8PortId)
		   {
		    case DIO_u8PORT_A : SET_BIT(DDRA,Copy_u8PinId);break;
		    case DIO_u8PORT_B : SET_BIT(DDRB,Copy_u8PinId);break;
		    case DIO_u8PORT_C : SET_BIT(DDRC,Copy_u8PinId);break;
		    case DIO_u8PORT_D : SET_BIT(DDRD,Copy_u8PinId);break;
		   }

	     }
		  else if (Copy_u8PinDir==DIO_u8INPUT)
		 {
		   switch (Copy_u8PortId)
		    {
		      case DIO_u8PORT_A : CLR_BIT(DDRA,Copy_u8PinId);break;
			  case DIO_u8PORT_B : CLR_BIT(DDRB,Copy_u8PinId);break;
			  case DIO_u8PORT_C : CLR_BIT(DDRC,Copy_u8PinId);break;
			  case DIO_u8PORT_D : CLR_BIT(DDRD,Copy_u8PinId);break;
		    }

		 }
	 }




	void DIO_voidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId, u8 Copy_u8PinVal)
	{
		//if ( Copy_u8PortId<=DIO_u8PORT_D&& Copy_u8PinId<=7)
			// {
				if(Copy_u8PinVal==DIO_u8HIGH)
				  {
				   switch (Copy_u8PortId)
				   {
				    case DIO_u8PORT_A : SET_BIT(PORTA,Copy_u8PinId);break;
				    case DIO_u8PORT_B : SET_BIT(PORTB,Copy_u8PinId);break;
				    case DIO_u8PORT_C : SET_BIT(PORTC,Copy_u8PinId);break;
				    case DIO_u8PORT_D : SET_BIT(PORTD,Copy_u8PinId);break;
				   }

			     }
				 else if (Copy_u8PinVal==DIO_u8LOW)
				 {
				   switch (Copy_u8PortId)
				    {
				      case DIO_u8PORT_A : CLR_BIT(PORTA,Copy_u8PinId);break;
					  case DIO_u8PORT_B : CLR_BIT(PORTB,Copy_u8PinId);break;
					  case DIO_u8PORT_C : CLR_BIT(PORTC,Copy_u8PinId);break;
					  case DIO_u8PORT_D : CLR_BIT(PORTD,Copy_u8PinId);break;
				    }

				// }

			  }


	}

	u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId)
	{
		u8 Local_BinVal;
		if(Copy_u8PinId<=7&&Copy_u8PortId<=DIO_u8PORT_D)
		{

			switch (Copy_u8PortId)
			{
			     case DIO_u8PORT_A: Local_BinVal = GET_BIT(PINA,Copy_u8PinId);break;
				 case DIO_u8PORT_B: Local_BinVal = GET_BIT(PINB,Copy_u8PinId);break;
				 case DIO_u8PORT_C: Local_BinVal = GET_BIT(PINC,Copy_u8PinId);break;
				 case DIO_u8PORT_D: Local_BinVal = GET_BIT(PIND,Copy_u8PinId) ;break;

			}
			return Local_BinVal;

		}
		else
		{
			 return 0xff;
		}



	}

	void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDir)
	{

				switch (Copy_u8PortId)
				{
				  case DIO_u8PORT_A: DDRA = Copy_u8PortDir;break;
				  case DIO_u8PORT_B: DDRB = Copy_u8PortDir;break;
				  case DIO_u8PORT_C: DDRC = Copy_u8PortDir;break;
				  case DIO_u8PORT_D: DDRD = Copy_u8PortDir;break;

				}

	}

	void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortVal)
	{
		    switch (Copy_u8PortId)
						{
						  case DIO_u8PORT_A: PORTA = Copy_u8PortVal;break;
						  case DIO_u8PORT_B: PORTB = Copy_u8PortVal;break;
						  case DIO_u8PORT_C: PORTC = Copy_u8PortVal;break;
						  case DIO_u8PORT_D: PORTD = Copy_u8PortVal;break;

						}
	}


