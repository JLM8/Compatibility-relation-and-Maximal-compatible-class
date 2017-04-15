#include "_Matrix.h"
#include<iostream>
using namespace std;
//矩阵类方法
//初始化
_Matrix::_Matrix(int mm,int nn){
	m = mm;
	n = nn;
	arr = new float[m * n];
	
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			*(arr + i * n + j)=0;
}


//释放
void _Matrix::free_matrix(){
	delete arr;
}


float _Matrix::read(int i,int j){
	if (i >= m || j >= n){
		cout<<"read i "<<i<<" j "<<j<<"  The data for reading have some wrong..."<<endl;
		system("pause");
		return 2222;
	//不知如何停止程序
	}else
		return *(arr + i * n + j);
}

//写入i,j坐标的数据
//失败返回-1,成功返回1
int _Matrix::write(int i,int j,float val){
	if (i >= m || j >= n){
		cout<<"i "<<i<<" j "<<j;
		cout<<"The data for writing have some wrong..."<<endl;
	}
	
	*(arr + i * n + j) = val;
	return 1;
}


void _Matrix::display(){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cout<<*(arr+i*n +j)<<"\t";
		cout<<endl;
	}
}
