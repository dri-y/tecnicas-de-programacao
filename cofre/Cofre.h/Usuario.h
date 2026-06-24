#ifndef COFRE_H
#define COFRE_H
#include <string>
#include "Usuario.h"
using namespace std;

class Cofre {
private:
 	static const int max_usuarios = 100;//coloquei const para tornar o tamanho do array fixo pelo código 
 	Usuario usuarios[max_usuarios];
 	int qtdUsuarios;
    bool aberto;
public:
    Cofre() {
        aberto = false;
        qtdUsuarios = 0;
    }
    
    bool adicionarUsuario(Usuario user) {
        if (qtdUsuarios < max_usuarios){
        	usuarios[qtdUsuarios] = user;
        	qtdUsuarios++;
        	
        	return true;
		}
		return false;
    }
    
    Usuario* getUsuarios() {
        return usuarios;
    }
    int getQtdUsuarios(){
    	return qtdUsuarios;
	}
    
    bool autenticar(int id, string senha) {
        for(int i = 0; i < qtdUsuarios; i++) {
            if(usuarios[i].getId() == id &&
               usuarios[i].verificarSenha(senha)) {
                return true;
            }
        }
        return false;
    }
    bool validarAdmin(int id, string senha) {
       for (int i = 0; i < qtdUsuarios; i++) {
           if (usuarios[i].getId() == id && usuarios[i].getSenha() == senha) {
            return usuarios[i].isAdmin();
           }
       }
        return false;
    }
    
    void abrir() {
        aberto = true;
    }
    
    void fechar() {
        aberto = false;
    }
    
    bool estaAberto() {
        return aberto;
    }
};
#endif
