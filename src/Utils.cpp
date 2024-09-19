#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "Utils.h"

namespace Utils {

	int randomNumberGenInRange(int min, int max) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(min, max);

		return distr(gen);
	}

	void printShaderLog(GLuint shader) {
		int len = 0;
		int charWritten = 0;
		char* log;

		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
		if (len > 0) {
			log = (char*)malloc(len);
			glGetShaderInfoLog(shader, len, &charWritten, log);
			std::cout << "Shader Info Log: " << log << std::endl;
			free(log);
		}
	}

	void printProgramLog(int program) {
		int len = 0;
		int charWritten = 0;
		char* log;

		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
		if (len > 0) {
			log = (char*)malloc(len);
			glGetProgramInfoLog(program, len, &charWritten, log);
			std::cout << "Program info log: " << log << std::endl;
			free(log);
		}
	}

	bool checkOpenGLError() {
		bool foundError = false;
		int glErr = glGetError();

		while (glErr != GL_NO_ERROR) {
			std::cout << "glError: " << glErr << std::endl;
			foundError = true;
			glErr = glGetError();
		}

		return foundError;
	}

}