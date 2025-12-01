class Ordem{
	private:
		int tam;
    public:
    	int *Lista;
    	Ordem();
    	~Ordem();
    	void Entrada(int n);
    	void Saida(int n);
    	void Bubble(int n);
    	void Insertion (int n);
    	void Selection (int n);
    	void Intercala (int p, int q, int r);
    	void Merge(int p, int r);
    	int Separa(int p, int r);
    	void Quick(int p, int r);
		void Aleatorio(int n);   
		int MenuOrdenar();
};
