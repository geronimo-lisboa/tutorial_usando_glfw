#include <GL\glew.h>
#include <map>
#include <string>
#include <sstream>

using namespace std;
class Shader
{
private:
	GLuint programId, vsId, fsId;
	map<string, GLuint> attributes;
	map<string, GLuint> uniforms;
	std::string ReadShaderFile(std::string path);
	void introspectProgram(GLuint programId, map<string, GLuint> &attributes, map<string, GLuint> &uniforms);
	string GetShaderInfoLog(GLuint object, PFNGLGETSHADERIVPROC glGet__iv, PFNGLGETSHADERINFOLOGPROC glGet__InfoLog);
	GLuint MakeShader(GLenum type, std::string source);
	GLuint MakeProgram(GLuint vertex_shader, GLuint fragment_shader);
public:
	Shader(string vsPath, string fsPath);
	Shader(stringstream vsStream, stringstream fsStream);
	~Shader();
	GLuint GetUniform(string name);
	GLuint GetAttribute(string name);
	GLuint GetProgramId();
	void UseProgram();
};