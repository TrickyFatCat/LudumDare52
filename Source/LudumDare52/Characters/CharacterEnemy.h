﻿// Copyright (c) 2023. Made by Title Goose Team during LudumDare 52. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "CharacterEnemy.generated.h"

UCLASS()
class LUDUMDARE52_API ACharacterEnemy : public ACharacterBase 
{
	GENERATED_BODY()

public:
	ACharacterEnemy();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};