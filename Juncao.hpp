
//Uma junção destinase a transformação de duas pistas em uma
class Juncao
{
    private:
        Pista *entrada1, *entrada2, *saida;
    public:
        void defineEntradasSaida( Pista *entrada1, Pista *entrada2, Pista *saida )
        {
            this->entrada1 = entrada1;
            this->entrada2 = entrada2;
            this->saida = saida;
        }
};