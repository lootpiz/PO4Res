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
	length += sprintf(buffer + length, "\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
	length += sprintf(buffer + length, "\t\t===================================\n");
	length += sprintf(buffer + length, "\t\t\t ��  ��  ��  �� \n");
	length += sprintf(buffer + length, "\t\t===================================\n\n");
	length += sprintf(buffer + length, "\t\t\t 1. �� �� �� �� \n");
	length += sprintf(buffer + length, "\t\t\t 2. �� �� �� �� \n");
	length += sprintf(buffer + length, "\t\t\t 3. �� �� �� �� \n");
	length += sprintf(buffer + length, "\t\t\t 4. �� �� �� �� \n");
	length += sprintf(buffer + length, "\t\t\t 5. �޴��� ���� \n");
	length += sprintf(buffer + length, "\t\t\t 6. ���̺� ���� \n\n");
	length += sprintf(buffer + length, "\t\t\t 0. �� �� �� �� \n");
	length += sprintf(buffer + length, "\t\t===================================\n");
	length += sprintf(buffer + length, "\t\t\t �޴��� �����ϼ���.");
	puts(buffer);
}

void PrintError()
{
	printf("\t\t �Է¿� ������ �ֽ��ϴ�.");
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
	printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t ��  ��  ��  �� \n");
	printf("\t\t===================================\n\n");
	printf("\t\t ������ �ο��� �Է��ϼ���.\n\t\t -> ");
	fflush(stdin); scanf("%d", &numberofpeople);
	tableIndex = table->Search(numberofpeople);

	if(tableIndex == -1)
	{
		printf("\t\t===================================\n\n");
		printf("\t\t �� ���̺��� ã�� �� �����ϴ�.");
	}
	else
	{
		table->GetTables()[tableIndex].SetTableCurrentPeople(numberofpeople);
		printf("\t\t===================================\n\n");
		printf("\t\t %d �� ���̺� ���� �� �ֽ��ϴ�.", tableIndex+1);
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
	printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t ��  ��  ��  �� \n");
	printf("\t\t===================================\n\n");
	printf("\t\t �ֹ��Ͻ� ������ ���̺� ��ȣ�� �Է��ϼ���. \n\t\t -> ");
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
			printf("\t\t �Է��Ͻ� ���뿡 ������ �ֽ��ϴ�.\n");
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
				printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
				printf("\t\t===================================\n");
				printf("\t\t\t ��  ��  ��  �� (TABLE No.%d)\n", tableNumber+1);
				printf("\t\t===================================\n\n");
				printf("\t\t �ֹ���ȣ : %s \n\n", order->GetOrders()[tableNumber].GetOrder()->GetSerialNumber() );
				printf("\t\t ��ȣ | ��           �� | ��       �� \n");
				for( int i = 0 ; i < menu->GetCount() ; i++)
				{
					printf("\t\t %4d | %15s | %8d �� \n", i+1, menu->GetMenu()[i].GetFoodName(), menu->GetMenu()[i].GetPrice() );
				}
				printf("\t\t===================================\n");
				printf("\t\t �ֹ��Ͻ� ������ ��ȣ�� �Է����ּ���. -> "); fflush(stdin); scanf("%d", &number);
				number--;
				printf("\t\t �ֹ��Ͻ� ������ ������ �Է����ּ���. -> "); fflush(stdin); scanf("%d", &count);
				dishName[number] = count;

				printf("\n\t\t===================================\n");
				printf("\t\t �ֹ��� ��� �Ͻðڽ��ϱ�? (Y/N) \n\t\t -> "); fflush(stdin); continueFlag = getch();
			}
			
			system("cls");
			printf("\n");
			printf("\n\t\t===================================\n");
			printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
			printf("\t\t===================================\n");
			printf("\t\t\t ��  ��  ��  �� (v)\n", tableNumber);
			printf("\t\t===================================\n\n");
			printf("\t\t �ֹ������� Ȯ���մϴ�.\n");
			printf("\t\t ��ȣ | ��           �� | ��       �� | ����\n");
			for( i = 0 ; i < menu->GetCount() ; i++)
			{
				printf("\t\t %4d | %15s | %8d �� | %3d ��\n",
						i+1, menu->GetMenu()[i].GetFoodName(), menu->GetMenu()[i].GetPrice(), dishName[i] );
			}

			printf("\t\t===================================\n");
			printf("\t\t �ֹ��Ͻ� ������ �½��ϱ�? (Y/N) \n\t\t -> "); fflush(stdin); correctFlag = getch();
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
				printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
				printf("\t\t===================================\n");
				printf("\t\t\t ��  ��  ��  �� (TABLE No.%d)\n", tableNumber);
				printf("\t\t===================================\n\n");
				printf("\t\t �Ʒ��� ������ �ֹ��մϴ�.\n");
				printf("\t\t ��ȣ | ��           �� | ��       �� | ����\n");
				for( i = 0 ; i < menu->GetCount() ; i++)
				{
					printf("\t\t %4d | %15s | %8d �� | %3d ��\n", i+1,
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
				printf("\t\t ���ֹ� �Ͻðڽ��ϱ�? (Y/N) \n\t\t -> "); fflush(stdin); resetFlag = getch();
				continueFlag = 'y';
			}
		}
	}
	else
	{
		printf("\t\t===================================\n");
		printf("\t\t ���� �մ��� �Ȱ輼��-.-\n");
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
	printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t ��  ��  ��  �� \n");
	printf("\t\t===================================\n\n");
	printf("\t\t �����Ͻ� ������ ���̺� ��ȣ�� �Է��ϼ���. \n\t\t ->");
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
			printf("\t\t ������ �Ͻðڽ��ϱ�?(Y/N) \n\t\t -> "); fflush(stdin); correctFlag = getch();		
		}
		else
		{
			printf("\t\t===================================\n");
			printf("\t\t �Է��Ͻ� ���뿡 ������ �ֽ��ϴ�.\n");			
		}

	
		if(correctFlag == 'Y' || correctFlag == 'y')
		{
			for (int i = 0; i < menu->GetCount(); i++)
			{
				price += (order->GetOrders()[tableNumber].GetDetails()[i].GetDish()->GetPrice()) * (order->GetOrders()[tableNumber].GetDetails()[i].GetCount());
		
			}
		}
		printf("\n\t\t �����Ͻ� �ݾ��� %8d �Դϴ�.\n", price);
		printf("\n\t\t===================================\n");
		printf("\t\t ��������� �����ϼ���. 1. ���� 2. ī�� \n\t\t -> ");
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
		printf("\t\t �����Ǿ����ϴ�.\n");
		getch();
		
		system("cls");
		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t ��  ��  ��  �� \n");
		printf("\t\t===================================\n\n");

		printf("\t\t �������� ����մϴ�. \n");
		printf("\t\t===================================\n");
		printf("\t\t ��¥ : %s\n", ((char*)Date::GetCurrentDate()));
		printf("\t\t �Ѿ� : %8d\n\n", price);
		printf("\t\t ��ȣ | ��           �� | ��       �� | �� ��\n");
		for( i = 0 ; i < menu->GetCount() ; i++)
		{
			if (order->GetOrders()[tableNumber].GetDetails()[i].GetCount()	> 0)
			{
				printf("\t\t %4d | %15s | %8d �� | %3d ��\n", i+1,
				menu->GetMenu()[i].GetFoodName(), 
				menu->GetMenu()[i].GetPrice(),
				order->GetOrders()[tableNumber].GetDetails()[i].GetCount()	);
			}
		}
		printf("\n\t\t===================================\n");
		printf("\t\t �̿��� �ּż� �����մϴ�.");
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
		printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t ��  ��  ��  �� \n");
		printf("\t\t===================================\n\n");
		today = Date::GetCurrentDate();

		printf("\t\t �˻��� ��¥�� ������ �Է��ϼ���.\n");
		printf("\t\t <�� : %s>\n", (char*)today); 
		printf("\t\t �������� : ");	fflush(stdin); scanf("%s", begin);
		printf("\t\t �������� : ");	fflush(stdin); scanf("%s", fin);

		//begindate.CastingDateForm(begindate);
		begindate.CastingDateForm(begin);
		//findate.CastingDateForm(findate);
		findate.CastingDateForm(fin);
		
		
		count = bill->Calculate(begindate, findate, &cashTotal, &chargeTotal, &Total);	

		printf("%d", count);		
		
		system("cls");

		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t ��  ��  ��  �� \n");
		printf("\t\t===================================\n\n");
		printf("\t\t\t �����Ѿ� :  %d", cashTotal);

		printf("\n\t\t\t ī���Ѿ� : %d", chargeTotal);
		printf("\n\n\t\t\t ��    �� : %d", Total);
		
		printf("\n\t\t===================================\n");		
		printf("\t\t ����Ͻðڽ��ϱ�? (Y/N) \n\t\t -> ");
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
	printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t ��  ��  ��  �� \n");
	printf("\t\t===================================\n\n");
	
	printf("\t\t ��ȣ | ��           �� | ��       ��\n");
	printf("\t\t===================================\n");

	for ( i = 0; i< menu->GetCount(); i++)
	{
		printf("\t\t %4d | %15s | %8d ��\n",
		i+1,
		menu->GetMenu()[i].GetFoodName(),
		menu->GetMenu()[i].GetPrice());
	}

	printf("\n\t\t �����Ͻ� ����� �����ϼ���. \n");
	printf("\t\t===================================\n");
	printf("\t\t 1. �����ϱ�  2. �߰��ϱ�  3. �����ϱ� \n\t\t ->");
	fflush(stdin); scanf("%d", &menuselect);

	system("cls");
	printf("\n");
	printf("\n\t\t===================================\n");
	printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t ��  ��  ��  �� \n");
	printf("\t\t===================================\n\n");
	
	printf("\t\t ��ȣ | ��           �� | ��       ��\n");
	printf("\t\t===================================\n");

	for ( i = 0; i< menu->GetCount(); i++)
	{
		printf("\t\t %4d | %15s | %8d ��\n",
		i+1,
		menu->GetMenu()[i].GetFoodName(),
		menu->GetMenu()[i].GetPrice());
	}



	if (menuselect == 1)
	{
			
		printf("\n\n\t\t===================================\n");
		printf("\t\t �����Ͻ� �޴��� �����ϼ���. \n\t\t ->");
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
				printf("\t\t �޴��� ã�� �� �����ϴ�.");
			}

			printf("\t\t===================================\n");
			printf("\t\t ������ ������ �Է��ϼ��� : ");
			fflush(stdin); scanf("%d", &modifyprice);

			printf("\t\t===================================\n");
			printf("\t\t �����Ͻ� �޴��� �����Ͻðڽ��ϱ�? (Y/N)  \n\t\t ->");
			fflush(stdin); correctFlag = getchar();
		
			if (correctFlag == 'y' || correctFlag == 'Y')
			{
				menu->GetMenu()[menunumber - 1].SetPrice(modifyprice);
				printf("\t\t===================================\n");
				printf("\t\t�޴��� �����ǿ����ϴ�.");
			}
			else
			{
				printf("\t\t===================================\n");
				printf("\t\t�޴� ������ ����Ͽ����ϴ�.");
			}
		}
		
	}
	else if (menuselect == 2)
	{
		printf("\t\t===================================\n");
		printf("\t\t �߰��� �޴��� ���ĸ��� �Է��ϼ��� : ");
		fflush(stdin); scanf("%s", &inputdish);
		printf("\t\t �߰��� �޴��� ������ �Է��ϼ��� : ");
		fflush(stdin); scanf("%d", &inputprice);
		printf("\t\t===================================\n");
		printf("\t\t �Է��Ͻ� �޴��� �߰��Ͻðڽ��ϱ�? (Y/N)  \n\t\t ->");
		fflush(stdin); correctFlag = getchar();

		if (correctFlag == 'y' || correctFlag == 'Y')
		{

			dish = new Dish(inputdish, inputprice);
			menu->GetMenu().AppendRear(*dish);

			menu->SetCount(menu->GetCount() + 1);

			printf("\t\t===================================\n");
			printf("\t\t�޴��� �߰��ǿ����ϴ�.");
		}
		else
		{
			printf("\t\t===================================\n");
			printf("\t\t�޴� �߰��� ����Ͽ����ϴ�.");
		}
		
	}
	else if (menuselect == 3)
	{
		printf("\n\n\t\t===================================\n");
		printf("\t\t �����Ͻ� �޴��� �����ϼ���. \n\t\t ->");
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
				printf("\t\t �޴��� ã�� �� �����ϴ�.");
			}

			printf("\t\t===================================\n");
			printf("\t\t �����Ͻ� �޴��� �����Ͻðڽ��ϱ�? (Y/N)  \n\t\t ->");
			fflush(stdin); correctFlag = getchar();
		
			if (correctFlag == 'y' || correctFlag == 'Y')
			{
				menu->GetMenu().DeleteItem(menunumber - 1);
				menu->SetCount(menu->GetCount() - 1);
				
				printf("\t\t===================================\n");
				printf("\t\t�޴��� �����ǿ����ϴ�.");
			}
			else
			{
				printf("\t\t===================================\n");
				printf("\t\t�޴� ������ ����Ͽ����ϴ�.");
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

	//�޴�
	system("cls");
	printf("\n");
	printf("\n\t\t===================================\n");
	printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
	printf("\t\t===================================\n");
	printf("\t\t\t �� �� �� ��  �� \n");
	printf("\t\t===================================\n\n");
	
	printf("\t\t ���̺� ��ȣ | �� �� �� �� �� \n");
	printf("\t\t===================================\n");

	//���̺� ���� ���

	if(tables->GetCount() == 0)
	{
		printf("\t\t ���� ���̺��� �����ϴ�.\n");
	}

	else if(tables->GetCount() > 0)
	{
		for (i = 0; i< tables->GetCount(); i++)
		{
			printf("\t\t %4d | %d ��\n", i+1, tables->GetTables()[i].GetTableMaxPeople());
		}
	}

	//���� ����
	printf("\t\t===================================\n");
	printf("\t\t 1. �����ϱ�  2. �߰��ϱ�  3. �����ϱ� \n\t\t ->"); fflush(stdin); scanf("%d", &select);

	//�޴�
	
	//����
	switch( select )
	{
	case 1:
		system("cls");
		printf("\n");
		printf("\n\t\t===================================\n");
		printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t �� �� �� ��  �� \n");
		printf("\t\t===================================\n\n");
		
		printf("\t\t ���̺� ��ȣ | �� �� �� �� �� \n");
		printf("\t\t===================================\n");

		if(tables->GetCount() == 0)
		{
			printf("\t\t ���� ���̺��� �����ϴ�.\n");
		}

		else if(tables->GetCount() > 0)
		{


			for (i = 0; i< tables->GetCount(); i++)
			{
				printf("\t\t %4d | %d ��\n", i+1, tables->GetTables()[i].GetTableMaxPeople());
			}

			printf("\n\n\t\t===================================\n");
			printf("\t\t ������ ���̺��� �����ϼ���. \n\t\t ->"); fflush(stdin); scanf("%d", &tableselect);

			if(tableselect < 0 || tableselect > tables->GetCount())
			{
				PrintError();
			}

			else
			{
				printf("\t\t===================================\n");
				printf("\t\t ���̺� ��ȣ : %d | ���� �ִ� �ο��� : %d\n\n", 
								tableselect, tables->GetTables()[tableselect-1].GetTableMaxPeople()); 
				printf("\n\t\t ������ �ִ� �ο����� �Է��ϼ��� : "); fflush(stdin); scanf("%d", &max);
				
				correct = 'a';
				while( correct != 'Y' && correct != 'y' && correct != 'N' && correct != 'n')
				{
					printf("\t\t �Է��Ͻ� ������ �����Ͻðڽ��ϱ�? (Y/N) "); fflush(stdin); scanf("%c", &correct);

					if( correct == 'Y' || correct == 'y')
					{
						tables->GetTables()[tableselect-1].SetTableMaxPeople(max);
						printf("\t\t===================================\n");
						printf("\t\t���������� �����Ǿ����ϴ�.\n");
					}

					else if( correct == 'N' || correct == 'n')
					{
						printf("\t\t===================================\n");
						printf("\t\t��ҵǾ����ϴ�.\n");
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
		printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t �� �� �� ��  �� \n");
		printf("\t\t===================================\n\n");
		
		printf("\t\t ���̺� ��ȣ | �� �� �� �� �� \n");
		printf("\t\t===================================\n");

		if(tables->GetCount() == 0)
		{
			printf("\t\t ���� ���̺��� �����ϴ�.\n");
		}

		else if(tables->GetCount() > 0)
		{
			for ( i = 0; i< tables->GetCount(); i++)
			{
				printf("\t\t %4d | %d ��\n", i+1, tables->GetTables()[i].GetTableMaxPeople());
			}
		}

		printf("\n\n\t\t===================================\n");
		printf("\t\t �߰��� ���̺��� �ִ� �ο����� �Է��ϼ���. \n\t\t ->"); fflush(stdin); scanf("%d", &max);
		
		correct = 'a';
		while(correct != 'Y' && correct != 'y' && correct != 'N' && correct != 'n')
		{
			printf("\t\t %d ���� ���� �� �ִ� ���̺��� �߰� �Ͻðڽ��ϱ�?(Y/N)_",max); fflush(stdin); scanf("%c", &correct);
			if(correct == 'Y' || correct == 'y')
			{
				//int GetTableNumber() const
				table = new Table(tables->GetCount()+1, max, 0);
				tables->GetTables().AppendRear(*table);
				tables->SetCount(tables->GetCount()+1);

				printf("\t\t===================================\n");
				printf("\t\t���������� ���̺��� �߰��Ǿ����ϴ�.");
			}

			else if(correct == 'N' || correct == 'n')
			{
				printf("\t\t===================================\n");
				printf("\t\t��ҵǾ����ϴ�.");
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
		printf("\t\t\t �ѿ츶�� ����/�ֹ� ver.1.0\n");
		printf("\t\t===================================\n");
		printf("\t\t\t �� �� �� ��  �� \n");
		printf("\t\t===================================\n\n");
		
		printf("\t\t ���̺� ��ȣ | �� �� �� �� �� \n");
		printf("\t\t===================================\n");

		if(tables->GetCount() == 0)
		{
			printf("\t\t ���� ���̺��� �����ϴ�.\n");
		}

		else if(tables->GetCount() > 0)
		{
			for ( i = 0; i< tables->GetCount(); i++)
			{
				printf("\t\t %4d | %d ��\n", i+1, tables->GetTables()[i].GetTableMaxPeople());
			}

			printf("\n\n\t\t===================================\n");
			printf("\t\t ������ ���̺��� �����ϼ���. \n\t\t ->"); fflush(stdin); scanf("%d", &tableselect);

			if(tableselect < 0 || tableselect > tables->GetCount())
			{
				PrintError();
			}

			printf("\n\n\t\t===================================\n");		

			correct = 'a';
			while(correct != 'Y' && correct != 'y' && correct != 'N' && correct != 'n')
			{
				printf("\t\t ������ ���̺��� ���� �Ͻðڽ��ϱ�? (Y/N)_"); fflush(stdin); scanf("%c", &correct);

				if(correct == 'Y' || correct == 'y')
				{
					tables->GetTables().DeleteItem(tableselect-1);
					tables->SetCount(tables->GetCount()-1);

					printf("\t\t===================================\n");
					printf("\t\t���̺��� �����ǿ����ϴ�.");
				}

				else if(correct == 'N' || correct == 'n')
				{
					
					printf("\t\t===================================\n");
					printf("\t\t ��ҵǾ����ϴ�.");
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

	


