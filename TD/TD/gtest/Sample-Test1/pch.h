//
// pch.h
// Header for standard system include files.
//

#pragma once
#include "gtest/gtest.h"
#include "../../EntityManager.h"
#include "../../EnemyWave.h"
#include "../../Tile.h"
#include "../../Trap.h"
#include "../../Castle.h"
#include "../../Lier.h"
#include "../../Effect.h"
#include "../../Enemy.h"
#include "../../Movesystem.h"
//#include "../../MoveSystem.h"


class TestSituation : ::testing::Environment
{
	void  SetUp()
	{
		std::cout << "I'm here in set up" << std::endl;
	}

	void TearDown()
	{
		std::cout << "I'm here in tear down" << std::endl;
	}
};
int clear_boy();