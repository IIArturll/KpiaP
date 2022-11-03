#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace MySpace {
	class Post
	{
	private:
		string post;
	public:
		Post();
		Post(string post);
		~Post();
		void setPost(string post);
		void showInfo();
	};
}
