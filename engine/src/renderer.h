#pragma once

#include "glad/glad.h"
#include <glfw/glfw3.h>
#include <array>
#include <vector>
#include "window.h"
#include "time.h"
#include "input.h"

namespace glr
{

	class shader
	{
	public:

		// Create shader object.
		shader(const char* vertexSrc = nullptr, const char* fragmentSrc = nullptr);

		~shader();

		// Compile shader.
		void compileShader(const char* vertexSrc, const char* fragmentSrc);

		// Bind shader.
		void bind() const;

		// Unbind shader.
		void unbind();

		// Set 4x4 Matrix uniform in shader.
		void setUniformMat4(const char* uniformName, const float* matrix);

	private:

		uint32_t _id;
	};


	class texture
	{
	public:

		// Create texture with filename.
		texture(const char* filename);

		~texture();

		// Set texture file.
		void setTexture(const char* filename);

		// Bind texture to texture slot.
		void bind(uint32_t slot) const;

		// Get texture width.
		inline uint32_t getWidth() const { return _width; }

		// Get texture height.
		inline uint32_t getHeight() const { return _height; }

	private:

		uint32_t _id;
		uint32_t _slot;

		uint32_t _width;
		uint32_t _height;
	};


	class vertexBuffer
	{
	public:

		// Create vertex buffer object with vector.
		vertexBuffer(const std::vector<float>& vertices);

		// Create vertex buffer object with begin ptr and element count.
		vertexBuffer(const float* vertices, uint32_t elements);

		~vertexBuffer();

		// Set vertex vertices data.
		void setVertexData(const float* vertices, uint32_t elements);

		// Bind vertex buffer.
		void bind() const;

		// Unbind vertex buffer.
		void unbind() const;

		// Get vertex buffer vertices amount.
		uint32_t getVertexAmount() const { return _vertexAmount; }

	private:

		uint32_t _vboId;
		uint32_t _vaoId;

		uint32_t _vertexAmount;
	};


	template<int S>
	struct vertexLayout
	{
	public:

		// Bind vertex layout.
		void bind() const;

	public:

		std::array<uint32_t, S> Amount = { 0 };
		std::array<uint32_t, S> DataType = { 0 };

		uint32_t Stride = 0;
	};


	struct vertexLayoutDynamic
	{
	public:

		// Create dynamic vertex layout object.
		vertexLayoutDynamic(uint32_t initialSize = 0);

		// Set vertex data amount.
		void setSize(uint32_t size);

		// Bind vertex layout.
		void bind() const;

	public:

		std::vector<uint32_t> Amount = { 0 };
		std::vector<uint32_t> DataType = { 0 };

		uint32_t Stride = 0;
	};


	class elementBuffer
	{
	public:

		// Create element buffer object wih begin ptr and element amount.
		elementBuffer(const uint32_t* indices, uint32_t elements);

		// Create element buffer object wih vector..
		elementBuffer(const std::vector<uint32_t>& indices);

		~elementBuffer();

		// Set element buffer data.
		void setElementData(const uint32_t* indices, uint32_t elements);

		// Bind the element buffer.
		void bind() const;

		// Unbind the element buffer
		void unbind() const;

		// Get amount of indices found in the element buffer.
		uint32_t getElementAmount() const { return _elementAmount; }

	private:

		uint32_t _id;
		uint32_t _elementAmount;
	};


	class renderer
	{
	public:

		struct rendererSettings
		{
		public:

			enum class cullingMode
			{
				None = 0,
				Front = GL_FRONT,
				Back = GL_BACK,
			};

			enum class depthTestingMode
			{
				None = 0,
				Always = GL_ALWAYS,
				Never = GL_NEVER,
				Less = GL_LESS,
				Equal = GL_EQUAL,
				Greater = GL_GREATER
			};

		public:

			cullingMode CullingMode = cullingMode::Back;
			depthTestingMode DepthTestingMode = depthTestingMode::None;

			std::array<float, 4> ClearColor = { 0, 0, 0, 1 };
		};

		// Creates renderer object.
		renderer(const window& window, const rendererSettings& settings);

		// Initializes the renderer.
		void init();

		// Clears the color and depth buffer.
		void clear() const;

		// Draws amount of indices on the screen.
		void draw(uint32_t elements) const;

		// Updates the renderer components.
		void update();

		// Returns a reference to the window object.
		const window& getWindow() const { return _window; }

		// Returns a reference to the time object
		const time& getTime() const { return _time; }

		// Returns a reference to the input object
		const input& getInput() const { return _input; }
		input* getInput() { return &_input; }

	private:

		window _window;
		time _time;
		input _input;
		rendererSettings _renderSettings;
	};

	// Returns the size in bytes of glfw data types.
	uint32_t glDatatypeSize(uint32_t type);

	// Cannot be included in the .cpp file, it causes a linking error.
	template<int S>
	inline void vertexLayout<S>::bind() const
	{

		uint32_t offset = 0;

		// Set stride and vertex layout.
		for (size_t i = 0; i < S; i++)
		{
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, Amount[i], DataType[i], GL_FALSE, Stride, (const void*)offset);

			offset += glDatatypeSize(DataType[i]) * Amount[i];
		}

	}


}