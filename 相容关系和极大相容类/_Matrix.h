#ifndef _MATRIX_H
#define _MATRIX_H

//矩阵数据结构
//二维矩阵
class _Matrix{
private:
public:
	int m;
	int n;
	float *arr;
	
	_Matrix(int mm = 0,int nn = 0);

	void free_matrix();
	//读取i,j坐标的数据
	//失败返回-31415,成功返回值
	float read(int i,int j);
	//写入i,j坐标的数据
	//失败返回-1,成功返回1
	int write(int i,int j,float val);

	void display();

};

#endif