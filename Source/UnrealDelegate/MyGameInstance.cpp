// Fill out your copyright notice in the Description page of Project Settings.

#include "Person.h"
#include "Staff.h"
#include "Student.h"
#include "Teacher.h"
#include "Card.h"
#include "CourseInfo.h"
#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("학교");
}

void UMyGameInstance::Init()
{
	Super::Init();

	// 인자로 this를 넣으면 해당 UCourseInfo 클래스 객체는 
	// MyGameInstance의 서브 오브젝트 객체가 되고 
	// MyGameInstance는 UCourseInfo의 Outer가 된다.
	CourseInfo = NewObject<UCourseInfo>(this);

	UE_LOG(LogTemp, Log, TEXT("=================================================="));

	UStudent* Student1 = NewObject<UStudent>();
	Student1->SetName(TEXT("학생1"));
	UStudent* Student2 = NewObject<UStudent>();
	Student2->SetName(TEXT("학생2"));
	UStudent* Student3 = NewObject<UStudent>();
	Student3->SetName(TEXT("학생3"));

	CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student2, &UStudent::GetNotification);
	CourseInfo->OnChanged.AddUObject(Student3, &UStudent::GetNotification);

	CourseInfo->ChangeCourseInfo(SchoolName, TEXT("변경된 학사 정보"));

	UE_LOG(LogTemp, Log, TEXT("=================================================="));
}
