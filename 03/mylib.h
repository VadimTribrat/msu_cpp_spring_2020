class Matrix
{
	int * * mat;
	size_t rows, columns;
	public:
	class Str
	{
		int * s;
		size_t columns;
		public:
		Str(int *, size_t);
		int & operator[](size_t i);
		Str(const Str &);
	};
	Matrix(size_t, size_t);
	~Matrix();
	Str operator[](size_t i);
	int getRows();
	int getColumns();
	int operator ==(const Matrix &);
	int operator !=(const Matrix &);
	Matrix & operator *=(int i);
};
