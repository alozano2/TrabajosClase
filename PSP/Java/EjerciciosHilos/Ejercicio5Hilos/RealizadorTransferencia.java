public class RealizadorTransferencia implements Runnable {
    Transferencia transfer;

    public RealizadorTransferencia(Transferencia transfer){
        this.transfer = transfer;
    }

    @Override
    public void run() {
        transfer.transferir();
    }
}
