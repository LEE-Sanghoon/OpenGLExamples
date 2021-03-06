// ExD2_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#ifdef WIN32
#include <Windows.h>
#include <GL\gl.h>
#include <GL\glu.h>  // glu는 선택사항임
#include <GL\glut.h>
#endif
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

#include <iostream>

void SetupRC();											// OpenGL 렌더링 환경에 대한 기본 설정 부분을 담당하는 함수

void RenderScene();										// 실제 렌더링 부분을 담당하는 함수
void ReshapeScene(int, int);							// 윈도우 크기 변경 설정 담당 함수


int main()
{
	//초기화 함수들

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);		// 디스플레이 모드 설정
	glutInitWindowPosition(100, 100);					// 윈도우의 위치 지정
	glutInitWindowSize(500, 500);						// 윈도우의 크기 지정
	glutCreateWindow("사각형 그리기");					// 윈도우 생성 (윈도우 이름)

														// 콜백 함수 등록
	glutDisplayFunc(RenderScene);						// 출력 함수의 지정
	glutReshapeFunc(ReshapeScene);						// 윈도우 크기 변경함수의 지정

	SetupRC();

	glutMainLoop();

	return 0;
}


void SetupRC()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);				// 바탕색을 검은색으로
	glShadeModel(GL_FLAT);								// 플랫 렌더링 모드로 전환
	glFrontFace(GL_CCW);								// 시계 반대 방향을 앞면으로
}


void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);						// 설정한 색으로 전체를 칠하기
	glPolygonMode(GL_BACK, GL_LINE);					// 뒷면은 선으로 그린다.

	glMatrixMode(GL_MODELVIEW);							// 모델 매트릭스모드로 전환
	glLoadIdentity();


	// 사각형 그리기
	glBegin(GL_TRIANGLE_STRIP);

	glColor3ub(0, 114, 188);
	glVertex3f(-25.0f, -25.0f, 0.0f);
	glVertex3f(25.0f, -25.0f, 0.0f);
	glVertex3f(-25.0f, 25.0f, 0.0f);
	glColor3ub(0, 52, 113);
	glVertex3f(25.0f, 25.0f, 0.0f);

	glEnd();

	glFlush();											// 화면에 출력하기
}


void ReshapeScene(int width, int height)
{
	float fRange = 100.0f;								// 화면의 크기를 결정하는 변수

	glViewport(0, 0, width, height);					// OpenGL 뷰포트를 윈도우 전체크기에 맞추어 변경한다.
	glMatrixMode(GL_PROJECTION);						// 프로젝션 매트릭스 초기화
	glLoadIdentity();

	// 직각투영으로 프로젝션 매트릭스를 초기화
	if (width <= height)
	{
		glOrtho(-fRange, fRange, -fRange * height / width, fRange * height / width, -fRange, fRange);
	}
	else
	{
		glOrtho(-fRange * width / height, fRange * width / height, -fRange, fRange, -fRange, fRange);
	}
}
