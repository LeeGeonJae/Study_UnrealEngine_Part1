// Fill out your copyright notice in the Description page of Project Settings.

#include "Card.h"
#include "Person.h"

UPerson::UPerson()
{
	Name = TEXT("홍길동");
	Card = CreateDefaultSubobject<UCard>(TEXT("NAME_Card"));
}
