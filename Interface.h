//Interface.h

#ifndef _INTERFACE_H
#define _INTERFACE_H

#include	"MenuInformation.h"
#include	"Billmanagement.h"
#include	"OrderSheetBinder.h"
#include	"TableInformation.h"
#include	"Dish.h"


void MainForm();
void CheckIn(BillManagement* bill, MenuInformation* menu,	OrderSheetBinder* order, TableInformation* table);
void PaymentForm(BillManagement* bill, MenuInformation* menu, OrderSheetBinder* order, TableInformation* table);
void MenuForm(MenuInformation* menu);
void CalculateForm(BillManagement* bill);
void BillForm();
void MenuForm();
void OrderForm(BillManagement* bill, MenuInformation* menu,	OrderSheetBinder* order, TableInformation* table);
void TableForm();
void PrintError();

#endif