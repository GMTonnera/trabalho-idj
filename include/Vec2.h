#pragma once

class Vec2 {
	public:
		float x, y;

		// Construtor que inicializa os atributos em 0
		Vec2();

		// Construtor que inicializa os atributos com determinados valores
		Vec2(float x, float y);

		// Soma com outro vetor
		Vec2 operator+(Vec2 vec);

		// Subtra��o com outro vetor
		Vec2 operator-(Vec2 vec);

		// Multiplica��o com um escalar
		Vec2 operator*(float n);

		// Retorna a magnitide do vetor
		float GetMagnitude();

		// Retorna o vetor normalizado 
		Vec2 GetNormalized();

		// Retorna a dist�ncia em rela��o a outro vetor
		float GetDistance(Vec2 vec);

		// Retorna o �ngulo do vetor em rela��o ao eixo x
		float GetAngule();

		// Retorna o �ngulo da reta formada pelos vetores
		float GetLineAngule(Vec2 vec);

		// Promove uma rota��o no vetor dado um �ngulo
		Vec2 Rotate(float angule);
};