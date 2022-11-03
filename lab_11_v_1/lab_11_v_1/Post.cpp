#include "Post.h"

MySpace::Post::Post()
{
	cout << "constr Post" << endl;
	post = "none";
}

MySpace::Post::Post(string post)
{
	cout << "constr Post" << endl;
	this->post = post;
}

MySpace::Post::~Post()
{
	cout << "destr post" << endl;
}

void MySpace::Post::setPost(string post)
{
	this->post = post;
}
void MySpace::Post::showInfo()
{
	cout << "post: " << post << endl;
}


