import java.io.Serializable;
import java.time.LocalDate;
import java.util.ArrayList;

public class Cliente extends Pessoa implements Serializable {
    private String escolaridade;
    public Cliente(String nome, String cpf) {
        super(nome, cpf);
    }

    public Cliente (){
        super();
    }

    public Cliente(String cpf, String nome, String endereco, String estadoCivil, String escolaridade, LocalDate dataNascimento) {
        super(cpf, nome, endereco, estadoCivil, dataNascimento);
        this.escolaridade = escolaridade;
    }

    public String getEscolaridade() { return escolaridade; }

    public void setEscolaridade(String escolaridade) { this.escolaridade = escolaridade; }

    public void imprimeCliente() {
        System.out.println("Nome: " + getNome());
        System.out.println("CPF: " + cpf);
        System.out.println("Endereço: " + getEndereco());
        System.out.println("Estado Civil: " + getEstadoCivil());
        System.out.println("Escolaridade: " + getEscolaridade());
        System.out.println("Data de Nascimento: " + getDataNascimento());
    }
}

