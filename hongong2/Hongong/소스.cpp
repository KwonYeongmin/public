/*
void map_setting()
{
	mapSize = 44;

	//맵을 2차원 배열로 동적할당시킴
	*map = (int**)malloc(sizeof(int*) * mapSize);
	for (int i = 0; i < mapSize; i++)
	{
		*map[i] = (int*)malloc(sizeof(int) * mapSize);
	}
	//동적할당 된 맵을 전부 빈 공간으로 초기화 시켜줌
	for (int i = 0; i < mapSize; i++)
		for (int j = 0; j < mapSize; j++)
			map[i][j] = SPACE;
	//타이머 시간 미정
	timer = 120;

	int num = mapSize / RMS;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			srand((unsigned)time(NULL) * (i + j));
			int **arr = RollingArray(randomMap[rand() % 2], rand() % 3, ((i == 0 && j == 0) || (i == num - 1 && j == num - 1)) ? 0 : (rand() % 5));
			for (int AH = RMS * i, height = 0; height < RMS; height++, AH++) {
				for (int AW = RMS * j, width = 0; width < RMS; width++, AW++) {
					map[AH][AW] = arr[height][width];
				}
			}
		}
	}

	for (int i = 0; i < mapSize; i++) {
		printf("i = %d, mapSize - 1 = %d\n", i, mapSize - 1);
		map[i][0] = WALL;
		map[0][i] = WALL;
		map[i][mapSize - 1] = WALL;
		map[mapSize - 1][i] = WALL;
	}

	FILE * fp = fopen("mapTest.txt", "wt");
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			fprintf(fp, "%s", pMap[map[i][j]]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	for (int i = 0; i < mapSize; i++)
		free(map[i]);
	free(map);
}

int** RollingArray(int MapArr[25][25], int num, int block) {
	int ** arr;
	printf("%d\n", num);
	arr = (int**)malloc(sizeof(int*) * RMS);
	for (int i = 0; i < RMS; i++)
		arr[i] = (int*)malloc(sizeof(int) * RMS);

	for (int i = 0; i < num; i++) {
		int tempArr[RMS][RMS] = { 0 };
		for (int ii = 0; ii < RMS; ii++) {
			for (int j1 = RMS - 1, j2 = 0; j2 < RMS; j1--, j2++) {
				arr[ii][j2] = MapArr[j1][ii];
			}
		}
	}

	if (num == 0)
		for (int i = 0; i < RMS; i++)
		{
			for (int j = 0; j < RMS; j++)
			{
				arr[i][j] = MapArr[i][j];
			}
		}
	int check[8] = { 0 };
	for (int i = 0; i < block; i++) {
		srand((unsigned)time(NULL) * (i + i));
		int random = rand() % 8;
		for (int i = 0; check[random]; i++) {
			if (i > 1000) {
				for (int j = 0; j < 8; j++)
					if (check[j] == 0) {
						random = j;
						break;
					}
			}
			else random = rand() % 8;
		}

		check[random] = 1;
		switch (random) {
		case 0:
			arr[1][0] = WALL;
			break;
		case 1:
			arr[0][1] = WALL;
			break;
		case 2:
			arr[0][RMS - 2] = WALL;
			break;
		case 3:
			arr[1][RMS - 1] = WALL;
			break;
		case 4:
			arr[RMS - 2][0] = WALL;
			break;
		case 5:
			arr[RMS - 1][1] = WALL;
			break;
		case 6:
			arr[RMS - 2][RMS - 1] = WALL;
			break;
		case 7:
			arr[RMS - 1][RMS - 2] = WALL;
			break;
		}
	}
	return arr;
}*/