template<typename T>
class Vector{
	int cs;
	int ms;
	T *arr;
	
	public:
		Vector()
		{
			cs = 0;
			ms = 1;
			arr = new T[ms];
		}
		
		void push_back(T d)
		{
			if(cs==ms)
			{
				T *oldArr = arr;
				ms = 2*ms;
				arr = new T[ms];
				for(int i=0;i<cs;i++)
				{
					arr[i] = oldArr[i];
				}
				delete []oldArr;
			}	
			arr[cs] = d;
			cs++;
		}
		
		void pop_back()
		{
			cs--;
		}
		T front()
		{
			return arr[0]; 
		}
		T back()
		{
			return arr[cs-1];
		}
		int size()
		{
			return cs;
		}
		int capacity()
		{
			return ms;
		}
		bool isEmpty()
		{
			return cs==ms;
		}
		T at(int i)
		{
			return arr[i];
		}
		T operator[](int i)
		{
			return arr[i];
		}
};
