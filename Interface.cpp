 //Interface.cpp
#include	"MenuInformation.h"
#include	"Billmanagement.h"
#include	"OrderSheetBinder.h"
#include	"TableInformation.h"
#include	"Dish.h"
#include	"Interface.h"
#include    "OrderSheet.h"
#include	"PayCash.h"
#include	"PayCharge.h"
#include <assert.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <string.h>

char* GetSerialNumber(OrderSheetBinder* order);

void MainForm()
{
	char buffer[1000];
	int length = 0;

	system("cls");

	length += sprintf(buffer + length, "\n\t\t===================================\n");
	length += sprintf(buffer + length, "\t\t\t 한우마을 결제/주문 ver.1.0\n");
	length += sprintf(buffer + length, "\t\t===================================\n");
	length += sprintf(buffer + length, "\t\t\t 메  인  메  뉴 \n");
	length += sprintf(buffer + length, "\t\t===================================\n\n");
	length += sprintf(buffer + length, "\t\t\t 1. 고 객 받 기 \n");
	length += sprintf(buffer + length, "\t\t\t 2. 주 문 하 기 \n");
	length += sprintf(buffer + length, "\t\t\t 3. 결 제 하 기 \n");
	length += sprintf(buffer + length, "\t\t\t 4. 정 산 하 기 \n");
	length += sprintf(buffer + length, "\t\t\t 5. 메뉴판 관리 \n");
	length += sprintf(buffer + length, "\t\t\t 6. 테이블 관리 \n\n");
	length += sprintf(buffer + length, "\t\t\t 0. 종 료 하 기 \n");
	length += sprintf(buffer + length, "\t\t===================================\n");
	length += sprintf(buffer + length, "\t\t\t 메뉴를 선택하세요.");
	puts(buffer);
}

void PrintError()
{
	printf("\t\t 입력에 오류가 있습니다.");
	getch();
}
void CheckIn(BillManagement* bill, MenuInformation* menu,	OrderSheetBinder* order, TableInformation* table)
{
	int numberofpeople;
	int tableIndex;
	Date today;
	char serialNumber[12];
	Order* temporder;


	system("cls");
	printf("\n");
	printf("\n\t\t===================================\n");
	printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t 고  객  받  기 \n");
	printf("\t\t===================================\n\n");
	printf("\t\t 고객님의 인원을 입력하세요.\n\t\t -> ");
	fflush(stdin); scanf("%d", &numberofpeople);
	tableIndex = table->Search(numberofpeople);

	if(tableIndex == -1)
	{
		printf("\t\t===================================\n\n");
		printf("\t\t 빈 테이블을 찾을 수 없습니다.");
	}
	else
	{
		table->GetTables()[tableIndex].SetTableCurrentPeople(numberofpeople);
		printf("\t\t===================================\n\n");
		printf("\t\t %d 번 테이블에 앉을 수 있습니다.", tableIndex+1);
	}	

	today = Date::GetCurrentDate();
	strcpy(serialNumber, GetSerialNumber(order));
	temporder = new Order(today, serialNumber);	
 
	OrderSheet ordersheet( &(table->GetTables()[tableIndex]), temporder );
		
	order->Append(ordersheet);


	getch();
}

void OrderForm(BillManagement* bill, MenuInformation* menu,	OrderSheetBinder* order, TableInformation* table)
{
	int tableNumber;
	int dishName[10];
	int number,count;
	int flag = 0;
	int i = 0;

	char continueFlag = 'y';
	char correctFlag;
	char resetFlag;

	Detail* detail;

	system("cls");
	printf("\n");
	printf("\n\t\t===================================\n");
	printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t 주  문  하  기 \n");
	printf("\t\t===================================\n\n");
	printf("\t\t 주문하실 고객님의 테이블 번호를 입력하세요. \n\t\t -> ");
	fflush(stdin); scanf("%d", &tableNumber);

	
	if( order->GetCount() != 0 )
	{
		while( flag == 0 || i < order->GetCount())
		{
			if ( order->GetOrders()[i].GetTable()->GetTableNumber() == tableNumber )
			{
				flag = 1;
			}
			i++;
		}

		if( flag != 0 )
		{
			tableNumber = i - 1;
			resetFlag = 'Y';
		}
		else
		{
			printf("\t\t===================================\n");
			printf("\t\t 입력하신 내용에 오류가 있습니다.\n");
			resetFlag = 'N';
		}

		while (resetFlag == 'Y' || resetFlag == 'y')
		{
			for(i = 0 ; i < 10 ; i++)
			{
				dishName[i] = 0;
			}
			while(continueFlag == 'Y' || continueFlag == 'y')
			{
				system("cls");
				printf("\n");
				printf("\n\t\t===================================\n");
				printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
				printf("\t\t===================================\n");
				printf("\t\t\t 주  문  하  기 (TABLE No.%d)\n", tableNumber+1);
				printf("\t\t===================================\n\n");
				printf("\t\t 주문번호 : %s \n\n", order->GetOrders()[tableNumber].GetOrder()->GetSerialNumber() );
				printf("\t\t 번호 | 메           뉴 | 가       격 \n");
				for( int i = 0 ; i < menu->GetCount() ; i++)
				{
					printf("\t\t %4d | %15s | %8d 원 \n", i+1, menu->GetMenu()[i].GetFoodName(), menu->GetMenu()[i].GetPrice() );
				}
				printf("\t\t===================================\n");
				printf("\t\t 주문하실 음식의 번호를 입력해주세요. -> "); fflush(stdin); scanf("%d", &number);
				number--;
				printf("\t\t 주문하실 음식의 수량을 입력해주세요. -> "); fflush(stdin); scanf("%d", &count);
				dishName[number] = count;

				printf("\n\t\t===================================\n");
				printf("\t\t 주문을 계속 하시겠습니까? (Y/N) \n\t\t -> "); fflush(stdin); continueFlag = getch();
			}
			
			system("cls");
			printf("\n");
			printf("\n\t\t===================================\n");
			printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
			printf("\t\t===================================\n");
			printf("\t\t\t 주  문  하  기 (v)\n", tableNumber);
			printf("\t\t===================================\n\n");
			printf("\t\t 주문내역을 확인합니다.\n");
			printf("\t\t 번호 | 메           뉴 | 가       격 | 수량\n");
			for( i = 0 ; i < menu->GetCount() ; i++)
			{
				printf("\t\t %4d | %15s | %8d 원 | %3d 개\n",
						i+1, menu->GetMenu()[i].GetFoodName(), menu->GetMenu()[i].GetPrice(), dishName[i] );
			}

			printf("\t\t===================================\n");
			printf("\t\t 주문하신 내역이 맞습니까? (Y/N) \n\t\t -> "); fflush(stdin); correctFlag = getch();
			printf("%c", correctFlag);

			if( correctFlag == 'Y' || correctFlag == 'y' )
			{
				for( i = 0 ; i < menu->GetCount() ; i++)
				{
					detail = new Detail;
					order->GetOrders()[tableNumber].GetDetails().AppendRear( *detail );
					order->GetOrders()[tableNumber].GetDetails()[i].SetDish( &(menu->GetMenu()[i]) );
					order->GetOrders()[tableNumber].GetDetails()[i].SetCount( dishName[i] );
				}
				system("cls");
				printf("\n");
				printf("\n\t\t===================================\n");
				printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
				printf("\t\t===================================\n");
				printf("\t\t\t 주  문  하  기 (TABLE No.%d)\n", tableNumber);
				printf("\t\t===================================\n\n");
				printf("\t\t 아래의 내역을 주문합니다.\n");
				printf("\t\t 번호 | 메           뉴 | 가       격 | 수량\n");
				for( i = 0 ; i < menu->GetCount() ; i++)
				{
					printf("\t\t %4d | %15s | %8d 원 | %3d 개\n", i+1,
						menu->GetMenu()[i].GetFoodName(), 
						menu->GetMenu()[i].GetPrice(),
						order->GetOrders()[tableNumber].GetDetails()[i].GetCount()	);
				}
				
				printf("\n\t\t===================================\n");
				printf("\t\t \n");
				resetFlag = 'N';
			}
			else 
			{
				printf("\n\t\t===================================\n");
				printf("\t\t 재주문 하시겠습니까? (Y/N) \n\t\t -> "); fflush(stdin); resetFlag = getch();
				continueFlag = 'y';
			}
		}
	}
	else
	{
		printf("\t\t===================================\n");
		printf("\t\t 현재 손님이 안계세요-.-\n");
	}
	getch();
}
void PaymentForm(BillManagement* bill, MenuInformation* menu, OrderSheetBinder* order, TableInformation* table)
{
	int tableNumber;
	int i = 0;
	int flag = 0;
	char correctFlag = 'y';
	int price = 0;
	int payselect;

	system("cls");
	printf("\n");
	printf("\n\t\t===================================\n");
	printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t 결  제  하  기 \n");
	printf("\t\t===================================\n\n");
	printf("\t\t 결제하실 고객님의 테이블 번호를 입력하세요. \n\t\t ->");
	fflush(stdin); scanf("%d", &tableNumber);


	if( order->GetCount() != 0 )
	{
		while( i < order->GetCount() || flag == 0 )
		{
			if (order->GetOrders()[i].GetTable()->GetTableNumber() == tableNumber)
			{
				flag = 1;
			}
			i++;
		}

		if( flag != 0 )
		{
			tableNumber = i - 1;
			printf("\t\t===================================\n");
			printf("\t\t 결제를 하시겠습니까?(Y/N) \n\t\t -> "); fflush(stdin); correctFlag = getch();		
		}
		else
		{
			printf("\t\t===================================\n");
			printf("\t\t 입력하신 내용에 오류가 있습니다.\n");			
		}

	
		if(correctFlag == 'Y' || correctFlag == 'y')
		{
			for (int i = 0; i < menu->GetCount(); i++)
			{
				price += (order->GetOrders()[tableNumber].GetDetails()[i].GetDish()->GetPrice()) * (order->GetOrders()[tableNumber].GetDetails()[i].GetCount());
		
			}
		}
		printf("\n\t\t 결제하실 금액은 %8d 입니다.\n", price);
		printf("\n\t\t===================================\n");
		printf("\t\t 결제방법을 선택하세요. 1. 현금 2. 카드 \n\t\t -> ");
		fflush(stdin); scanf("%d", &payselect); 
		

		if (payselect == 1)
		{
			//PayCash paycash(Date::GetCurrentDate(), price);
			Payment payment1(Date::GetCurrentDate(), price, 1);
			//bill->GetBills().AppendRear(paycash);
			bill->GetBills().AppendRear(payment1);
			bill->SetCount(bill->GetCount() + 1);

		}
		else if (payselect == 2)
		{
			//PayCharge paycharge(Date::GetCurrentDate(), price);
			Payment payment2(Date::GetCurrentDate(), price, 2);
			//bill->GetBills().AppendRear(paycharge);
			bill->GetBills().AppendRear(payment2);
			bill->SetCount(bill->GetCount() + 1);

		}
		else
		{
			PrintError();
		}

		printf("\t\t===================================\n");
		printf("\t\t 결제되었습니다.\n");
		getch();
		
		system("cls");
		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t 결  제  하  기 \n");
		printf("\t\t===================================\n\n");

		printf("\t\t 영수증을 출력합니다. \n");
		printf("\t\t===================================\n");
		printf("\t\t 날짜 : %s\n", ((char*)Date::GetCurrentDate()));
		printf("\t\t 총액 : %8d\n\n", price);
		printf("\t\t 번호 | 메           뉴 | 가       격 | 수 량\n");
		for( i = 0 ; i < menu->GetCount() ; i++)
		{
			if (order->GetOrders()[tableNumber].GetDetails()[i].GetCount()	> 0)
			{
				printf("\t\t %4d | %15s | %8d 원 | %3d 개\n", i+1,
				menu->GetMenu()[i].GetFoodName(), 
				menu->GetMenu()[i].GetPrice(),
				order->GetOrders()[tableNumber].GetDetails()[i].GetCount()	);
			}
		}
		printf("\n\t\t===================================\n");
		printf("\t\t 이용해 주셔서 감사합니다.");
	}
	getch();
}

void CalculateForm(BillManagement* bill)
{
	Date today;
	Date begindate;
	Date findate;
	
	char begin[11];
	char fin[11];

	int cashTotal = 0;
	int chargeTotal = 0;
	int Total = 0;

	int count;

	char continueFlag = 'Y';
	while(continueFlag == 'y' || continueFlag == 'Y') 
	{

		system("cls");
		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t 정  산  하  기 \n");
		printf("\t\t===================================\n\n");
		today = Date::GetCurrentDate();

		printf("\t\t 검색할 날짜의 범위를 입력하세요.\n");
		printf("\t\t <예 : %s>\n", (char*)today); 
		printf("\t\t 시작일자 : ");	fflush(stdin); scanf("%s", begin);
		printf("\t\t 종료일자 : ");	fflush(stdin); scanf("%s", fin);

		//begindate.CastingDateForm(begindate);
		begindate.CastingDateForm(begin);
		//findate.CastingDateForm(findate);
		findate.CastingDateForm(fin);
		
		
		count = bill->Calculate(begindate, findate, &cashTotal, &chargeTotal, &Total);	

		printf("%d", count);		
		
		system("cls");

		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t 정  산  하  기 \n");
		printf("\t\t===================================\n\n");
		printf("\t\t\t 현금총액 :  %d", cashTotal);

		printf("\n\t\t\t 카드총액 : %d", chargeTotal);
		printf("\n\n\t\t\t 총    계 : %d", Total);
		
		printf("\n\t\t===================================\n");		
		printf("\t\t 계속하시겠습니까? (Y/N) \n\t\t -> ");
		fflush(stdin); continueFlag = getchar();
	}

}


void MenuForm(MenuInformation* menu)
{
	int i;
	int menuselect;
	int menunumber;
	int modifyprice;
	char correctFlag;
	int menuindex;
	
	char inputdish[20];
	int inputprice;

	Dish* dish;

	system("cls");
	printf("\n");
	printf("\n\t\t===================================\n");
	printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t 메  뉴  관  리 \n");
	printf("\t\t===================================\n\n");
	
	printf("\t\t 번호 | 메           뉴 | 가       격\n");
	printf("\t\t===================================\n");

	for ( i = 0; i< menu->GetCount(); i++)
	{
		printf("\t\t %4d | %15s | %8d 원\n",
		i+1,
		menu->GetMenu()[i].GetFoodName(),
		menu->GetMenu()[i].GetPrice());
	}

	printf("\n\t\t 수정하실 방법을 선택하세요. \n");
	printf("\t\t===================================\n");
	printf("\t\t 1. 수정하기  2. 추가하기  3. 삭제하기 \n\t\t ->");
	fflush(stdin); scanf("%d", &menuselect);

	system("cls");
	printf("\n");
	printf("\n\t\t===================================\n");
	printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t 메  뉴  수  정 \n");
	printf("\t\t===================================\n\n");
	
	printf("\t\t 번호 | 메           뉴 | 가       격\n");
	printf("\t\t===================================\n");

	for ( i = 0; i< menu->GetCount(); i++)
	{
		printf("\t\t %4d | %15s | %8d 원\n",
		i+1,
		menu->GetMenu()[i].GetFoodName(),
		menu->GetMenu()[i].GetPrice());
	}



	if (menuselect == 1)
	{
			
		printf("\n\n\t\t===================================\n");
		printf("\t\t 수정하실 메뉴을 선택하세요. \n\t\t ->");
		fflush(stdin); scanf("%d", &menunumber);

		if (menunumber > menu->GetCount())
		{
			PrintError();
		}
		else
		{
			menuindex = menu->Search(menu->GetMenu()[menunumber - 1].GetFoodName());

			if(menuindex == -1)
			{
				printf("\t\t===================================\n\n");
				printf("\t\t 메뉴를 찾을 수 없습니다.");
			}

			printf("\t\t===================================\n");
			printf("\t\t 수정될 가격을 입력하세요 : ");
			fflush(stdin); scanf("%d", &modifyprice);

			printf("\t\t===================================\n");
			printf("\t\t 선택하신 메뉴를 수정하시겠습니까? (Y/N)  \n\t\t ->");
			fflush(stdin); correctFlag = getchar();
		
			if (correctFlag == 'y' || correctFlag == 'Y')
			{
				menu->GetMenu()[menunumber - 1].SetPrice(modifyprice);
				printf("\t\t===================================\n");
				printf("\t\t메뉴가 수정되였습니다.");
			}
			else
			{
				printf("\t\t===================================\n");
				printf("\t\t메뉴 수정을 취소하였습니다.");
			}
		}
		
	}
	else if (menuselect == 2)
	{
		printf("\t\t===================================\n");
		printf("\t\t 추가할 메뉴의 음식명을 입력하세요 : ");
		fflush(stdin); scanf("%s", &inputdish);
		printf("\t\t 추가할 메뉴의 가격을 입력하세요 : ");
		fflush(stdin); scanf("%d", &inputprice);
		printf("\t\t===================================\n");
		printf("\t\t 입력하신 메뉴를 추가하시겠습니까? (Y/N)  \n\t\t ->");
		fflush(stdin); correctFlag = getchar();

		if (correctFlag == 'y' || correctFlag == 'Y')
		{

			dish = new Dish(inputdish, inputprice);
			menu->GetMenu().AppendRear(*dish);

			menu->SetCount(menu->GetCount() + 1);

			printf("\t\t===================================\n");
			printf("\t\t메뉴가 추가되였습니다.");
		}
		else
		{
			printf("\t\t===================================\n");
			printf("\t\t메뉴 추가을 취소하였습니다.");
		}
		
	}
	else if (menuselect == 3)
	{
		printf("\n\n\t\t===================================\n");
		printf("\t\t 삭제하실 메뉴을 선택하세요. \n\t\t ->");
		fflush(stdin); scanf("%d", &menunumber);

		if (menunumber > menu->GetCount())
		{
			PrintError();
		}
		else
		{
			menuindex = menu->Search(menu->GetMenu()[menunumber - 1].GetFoodName());

			if(menuindex == -1)
			{
				printf("\t\t===================================\n\n");
				printf("\t\t 메뉴를 찾을 수 없습니다.");
			}

			printf("\t\t===================================\n");
			printf("\t\t 선택하신 메뉴를 삭제하시겠습니까? (Y/N)  \n\t\t ->");
			fflush(stdin); correctFlag = getchar();
		
			if (correctFlag == 'y' || correctFlag == 'Y')
			{
				menu->GetMenu().DeleteItem(menunumber - 1);
				menu->SetCount(menu->GetCount() - 1);
				
				printf("\t\t===================================\n");
				printf("\t\t메뉴가 삭제되였습니다.");
			}
			else
			{
				printf("\t\t===================================\n");
				printf("\t\t메뉴 삭제을 취소하였습니다.");
			}
		}
	}
	else
	{
		PrintError();
	}
	//fflush(stdin); scanf("%d", &tableNumber);

	getch();
}
void BillForm()
{
}

void TableForm(TableInformation* tables)
{
	int select;
	int tableselect;
	int max;
	char correct = 'Y';
	int i;
	Table* table;

	//메뉴
	system("cls");
	printf("\n");
	printf("\n\t\t===================================\n");
	printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t 테 이 블 관  리 \n");
	printf("\t\t===================================\n\n");
	
	printf("\t\t 테이블 번호 | 최 대 인 원 수 \n");
	printf("\t\t===================================\n");

	//테이블 정보 출력

	if(tables->GetCount() == 0)
	{
		printf("\t\t 현재 테이블이 없습니다.\n");
	}

	else if(tables->GetCount() > 0)
	{
		for (i = 0; i< tables->GetCount(); i++)
		{
			printf("\t\t %4d | %d 명\n", i+1, tables->GetTables()[i].GetTableMaxPeople());
		}
	}

	//수정 선택
	printf("\t\t===================================\n");
	printf("\t\t 1. 수정하기  2. 추가하기  3. 삭제하기 \n\t\t ->"); fflush(stdin); scanf("%d", &select);

	//메뉴
	
	//선택
	switch( select )
	{
	case 1:
		system("cls");
		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t 테 이 블 관  리 \n");
		printf("\t\t===================================\n\n");
		
		printf("\t\t 테이블 번호 | 최 대 인 원 수 \n");
		printf("\t\t===================================\n");

		if(tables->GetCount() == 0)
		{
			printf("\t\t 현재 테이블이 없습니다.\n");
		}

		else if(tables->GetCount() > 0)
		{


			for (i = 0; i< tables->GetCount(); i++)
			{
				printf("\t\t %4d | %d 명\n", i+1, tables->GetTables()[i].GetTableMaxPeople());
			}

			printf("\n\n\t\t===================================\n");
			printf("\t\t 수정할 테이블을 선택하세요. \n\t\t ->"); fflush(stdin); scanf("%d", &tableselect);

			if(tableselect < 0 || tableselect > tables->GetCount())
			{
				PrintError();
			}

			else
			{
				printf("\t\t===================================\n");
				printf("\t\t 테이블 번호 : %d | 현재 최대 인원수 : %d\n\n", 
								tableselect, tables->GetTables()[tableselect-1].GetTableMaxPeople()); 
				printf("\n\t\t 수정할 최대 인원수를 입력하세요 : "); fflush(stdin); scanf("%d", &max);
				
				correct = 'a';
				while( correct != 'Y' && correct != 'y' && correct != 'N' && correct != 'n')
				{
					printf("\t\t 입력하신 정보로 수정하시겠습니까? (Y/N) "); fflush(stdin); scanf("%c", &correct);

					if( correct == 'Y' || correct == 'y')
					{
						tables->GetTables()[tableselect-1].SetTableMaxPeople(max);
						printf("\t\t===================================\n");
						printf("\t\t정상적으로 수정되었습니다.\n");
					}

					else if( correct == 'N' || correct == 'n')
					{
						printf("\t\t===================================\n");
						printf("\t\t취소되었습니다.\n");
					}

					else
					{
						printf("\t\t===================================\n");
						PrintError();
						printf("\n");
					}
				}
				
				getch();
			}
		}
		break;

	case 2:
		system("cls");
		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t 테 이 블 관  리 \n");
		printf("\t\t===================================\n\n");
		
		printf("\t\t 테이블 번호 | 최 대 인 원 수 \n");
		printf("\t\t===================================\n");

		if(tables->GetCount() == 0)
		{
			printf("\t\t 현재 테이블이 없습니다.\n");
		}

		else if(tables->GetCount() > 0)
		{
			for ( i = 0; i< tables->GetCount(); i++)
			{
				printf("\t\t %4d | %d 명\n", i+1, tables->GetTables()[i].GetTableMaxPeople());
			}
		}

		printf("\n\n\t\t===================================\n");
		printf("\t\t 추가할 테이블의 최대 인원수를 입력하세요. \n\t\t ->"); fflush(stdin); scanf("%d", &max);
		
		correct = 'a';
		while(correct != 'Y' && correct != 'y' && correct != 'N' && correct != 'n')
		{
			printf("\t\t %d 명이 앉을 수 있는 테이블을 추가 하시겠습니까?(Y/N)_",max); fflush(stdin); scanf("%c", &correct);
			if(correct == 'Y' || correct == 'y')
			{
				//int GetTableNumber() const
				table = new Table(tables->GetCount()+1, max, 0);
				tables->GetTables().AppendRear(*table);
				tables->SetCount(tables->GetCount()+1);

				printf("\t\t===================================\n");
				printf("\t\t정상적으로 테이블이 추가되었습니다.");
			}

			else if(correct == 'N' || correct == 'n')
			{
				printf("\t\t===================================\n");
				printf("\t\t취소되었습니다.");
			}

			else
			{
				printf("\t\t===================================\n");
				PrintError();
				printf("\n");
			}
		
		}

		getch();

		break;

	case 3:
		system("cls");
		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t 한우마을 결제/주문 ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t 테 이 블 관  리 \n");
		printf("\t\t===================================\n\n");
		
		printf("\t\t 테이블 번호 | 최 대 인 원 수 \n");
		printf("\t\t===================================\n");

		if(tables->GetCount() == 0)
		{
			printf("\t\t 현재 테이블이 없습니다.\n");
		}

		else if(tables->GetCount() > 0)
		{
			for ( i = 0; i< tables->GetCount(); i++)
			{
				printf("\t\t %4d | %d 명\n", i+1, tables->GetTables()[i].GetTableMaxPeople());
			}

			printf("\n\n\t\t===================================\n");
			printf("\t\t 삭제할 테이블을 선택하세요. \n\t\t ->"); fflush(stdin); scanf("%d", &tableselect);

			if(tableselect < 0 || tableselect > tables->GetCount())
			{
				PrintError();
			}

			printf("\n\n\t\t===================================\n");		

			correct = 'a';
			while(correct != 'Y' && correct != 'y' && correct != 'N' && correct != 'n')
			{
				printf("\t\t 선택한 테이블을 삭제 하시겠습니까? (Y/N)_"); fflush(stdin); scanf("%c", &correct);

				if(correct == 'Y' || correct == 'y')
				{
					tables->GetTables().DeleteItem(tableselect-1);
					tables->SetCount(tables->GetCount()-1);

					printf("\t\t===================================\n");
					printf("\t\t테이블이 삭제되였습니다.");
				}

				else if(correct == 'N' || correct == 'n')
				{
					
					printf("\t\t===================================\n");
					printf("\t\t 취소되었습니다.");
				}

				else
				{
					printf("\t\t===================================\n");
					PrintError();
					printf("\n");
				}
			}
			getch();

		}
		break;

	default:
		PrintError();
		break;

	}
}

/*************************************************************************/
/* TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST */
/*************************************************************************/
int main(void)
{
	BillManagement bill;
	MenuInformation menu;
	OrderSheetBinder order;
	TableInformation table;

	int select;

	MainForm();
	printf("\t\t\t -> ");
	scanf("%d", &select);

	while ( select != 0 )
	{
		switch ( select )
		{
		case 1 :
			CheckIn(&bill, &menu, &order, &table);
			break;
		case 2 :
			OrderForm(&bill, &menu, &order, &table);
			break;			
		case 3 :
			PaymentForm(&bill, &menu, &order, &table);
			break;			
		case 4 : 
			CalculateForm(&bill);
			break;
		case 5 :
			MenuForm(&menu);
			break;
		case 6 :
			TableForm(&table);
			break;
		default:
			PrintError();
			break;			
		}
		MainForm();
		printf("\t\t\t -> ");
		scanf("%d", &select);
	}
	return 0;
}

char* GetSerialNumber(OrderSheetBinder* order)
{
	Date date;
	char*today;
	int number;
	static char buffer[12];
	
	date = Date::GetCurrentDate();
	today = (char*)date;

	number = order->GetCount() + 1;

	sprintf(buffer,"%s-%03d", today, number);

	return buffer;
}

	


