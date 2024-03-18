import java.io.Serializable;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.InputMismatchException;

public abstract class Pessoa implements ValidaCPF, Classificavel, Serializable {
    protected String cpf;
    protected String nome;
    protected String endereco;
    protected String estadoCivil;
    protected LocalDate dataNascimento;

    public Pessoa() {
    }
    public Pessoa(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
    }
    public Pessoa(String cpf, String nome, String endereco, String estadoCivil, LocalDate dataNascimento) {
        this.cpf = cpf;
        this.nome = nome;
        this.endereco = endereco;
        this.estadoCivil = estadoCivil;
        if(dataNascimento == null)
            throw new DataNulaExecption("Data não pode ser nula");
        this.dataNascimento = dataNascimento;
    }

    public String getCPF() { return cpf; }
    public String getNome() { return nome; }
    public String getEndereco() { return endereco; }
    public String getEstadoCivil() { return estadoCivil; }
    public String getDataNascimento() { return dataNascimento.format(DateTimeFormatter.ofPattern("dd/MM/yyyy")); }
    public int getDiaNascimento() { return dataNascimento.getDayOfMonth(); }
    public int getMesNascimento() { return dataNascimento.getMonthValue(); }
    public int getAnoNascimento() { return dataNascimento.getYear(); }

    public void setcpf(String cpf) { this.cpf = cpf; }
    public void setNome(String nome) { this.nome = nome; }
    public void setEndereco(String endereco) { this.endereco = endereco; }
    public void setEstadoCivil(String estadoCivil) { this.estadoCivil = estadoCivil; }

    public boolean validaCPF(String cpf) {
        if (cpf.equals("00000000000") || cpf.equals("11111111111") ||
            cpf.equals("22222222222") || cpf.equals("33333333333") ||
            cpf.equals("44444444444") || cpf.equals("55555555555") ||
            cpf.equals("66666666666") || cpf.equals("77777777777") ||
            cpf.equals("88888888888") || cpf.equals("99999999999") ||
            (cpf.length() != 11))
            return (false);

        char dig10, dig11;
        int sm, i, r, num, peso;

        try {
            sm = 0;
            peso = 10;
            for (i = 0; i < 9; i++) {
                num = (int) (cpf.charAt(i) - 48);
                sm = sm + (num * peso);
                peso = peso - 1;
            }

            r = 11 - (sm % 11);
            if ((r == 10) || (r == 11))
                dig10 = '0';
            else dig10 = (char) (r + 48);

            sm = 0;
            peso = 11;
            for (i = 0; i < 10; i++) {
                num = (int) (cpf.charAt(i) - 48);
                sm = sm + (num * peso);
                peso = peso - 1;
            }

            r = 11 - (sm % 11);
            if ((r == 10) || (r == 11))
                dig11 = '0';
            else dig11 = (char) (r + 48);

            return (dig10 == cpf.charAt(9)) && (dig11 == cpf.charAt(10));
        } catch (InputMismatchException erro) {
            return (false);
        }
    }
    public boolean eMenorQue(Classificavel o){
        Pessoa compara = (Pessoa) o;
        return cpf.compareToIgnoreCase(compara.cpf) < 0;
    }
}
