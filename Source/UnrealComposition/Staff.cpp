// Fill out your copyright notice in the Description page of Project Settings.

#include "Card.h"
#include "Staff.h"

UStaff::UStaff()
{
	Name = TEXT("이직원");
	Card->SetCardType(ECardType::Staff);
}
