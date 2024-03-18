import java.time.LocalDate;

public class Transacao {
    private Conta conta;
    private LocalDate data;
    private double valor;
    private String canal;

    public Transacao(Conta conta, LocalDate data, double valor, String canal) {
        this.conta = conta;
        this.data = data;
        this.valor = valor;
        this.canal = canal;
    }

    public Conta getConta() {
        return conta;
    }

    public void setConta(Conta conta) {
        this.conta = conta;
    }

    public LocalDate getData() {
        return data;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public String getCanal() {
        return canal;
    }

    public void setCanal(String canal) {
        this.canal = canal;
    }
}

