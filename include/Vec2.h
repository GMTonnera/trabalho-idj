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

		// Subtração com outro vetor
		Vec2 operator-(Vec2 vec);

		// Multiplicação com um escalar
		Vec2 operator*(float n);

		// Retorna a magnitide do vetor
		float GetMagnitude();

		// Retorna o vetor normalizado 
		Vec2 GetNormalized();

		// Retorna a distância em relação a outro vetor
		float GetDistance(Vec2 vec);

		// Retorna o ângulo do vetor em relação ao eixo x
		float GetAngule();

		// Retorna o ângulo da reta formada pelos vetores
		float GetLineAngule(Vec2 vec);

		// Promove uma rotação no vetor dado um ângulo
		Vec2 Rotate(float angule);
};