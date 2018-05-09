#include <stdio.h>
#include <stdint.h>

#define OPALU 0
#define OPLW  35
#define OPSW  43
#define OPBEQ 4
#define OPJ   2

#define FNADD 32
#define FNSUB 34
#define FNAND 36
#define FNOR  37
#define FNSLT 42

#define MSIZE 256

char M[MSIZE]; // Memory

int32_t readword(uint32_t addr) {
	return *((int32_t *)&M[addr]);
}

void writeword(uint32_t addr, int32_t data) {
	*((int32_t *)&M[addr]) = data;
}

int32_t R[32]; // General Purpose Registers

uint32_t PC; // Program Pointer

uint32_t IR; // Instruction Register

#define GETOP(ir) ((ir>>26) & 63)
#define GETRS(ir) ((ir>>21) & 31)
#define GETRT(ir) ((ir>>16) & 31)
#define GETRD(ir) ((ir>>11) & 31)
#define GETSM(ir) ((ir>>6) & 31)
#define GETFN(ir) (ir & 63)
#define GETIM(ir) (ir & 0xffff)
#define GETAD(ir) (ir & 0x3ffffff)

void fetch() {
	IR = (uint32_t) readword(PC);
	PC = PC + 4; // beq and j will change this in execution
}

void init() {
	int32_t d[2] = {-1, 1};
	for(int i=0; i<32; i++) { R[i] = 0; }
	for(int i=0; i<MSIZE/4; i++) { writeword(4*i, d[i%2]); }

	writeword(0, (OPLW<<26) | (1<<16) | (MSIZE-4)); // lw $1, $0(252)
	writeword(4, (OPLW<<26) | (2<<16) | (MSIZE-8)); // lw $2, $0(0)
	writeword(8, (OPBEQ<<26) | (1<<21) | (2<<16) | 7); // beq $1, $2, 7
	writeword(12, (2<<21) | (1<<16) | (2<<11) | FNSUB); // sub $2, $2, $1
	writeword(16, (2<<21) | (2<<16) | (3<<11) | FNADD); // add $3, $2, $2
	writeword(20, (3<<21) | (2<<16) | (4<<11) | FNAND); // and $4, $3, $2
	writeword(24, (4<<21) | (2<<16) | (5<<11) | FNOR); // or $5, $4, $2
	writeword(28, (5<<21) | (2<<16) | (6<<11) | FNSLT); // slt $6, $5, $2
	writeword(32, (OPSW<<26) | (6<<16) | 60); // sw $6, $0(60)
	writeword(36, (OPJ<<26) | 2); // j 2
	writeword(40, (OPJ<<26)); // j 0

	PC = 0;
}

void showregs() {
	printf("\n");
	for(int i=0; i<MSIZE/4; i++) {
		printf("M[%d]=%d ", 4*i, readword(4*i));
	}

	printf("\n\n");

	for(int i=0; i<32; i++) {
		printf("$%d=%d ", i, R[i]);
	}
	printf("\n\nPC=%d IR=%08x\n", PC, IR);
}

int main() {

	unsigned int op, rs, rt, rd, sm, fn;
	int im, ad;

	init();

	showregs();

	while(1) {
		if(PC >= MSIZE) { printf("\n!!! PC out of range !!!\n"); break; }

		printf("\nPress a key to continue ...");
		getchar();

		fetch();
		//printf("\nPC=%d IR=%08x\n", PC, IR);

		op = GETOP(IR);
		rs = GETRS(IR);
		rt = GETRT(IR);
		rd = GETRD(IR);
		sm = GETSM(IR);
		fn = GETFN(IR);
		im = GETIM(IR);
		ad = GETAD(IR);

		switch(op) {
			case OPALU:
				switch(fn) {
					case FNADD:
						printf("\nExecuting: add $%d, $%d, $%d\n", rd, rs, rt);
						R[rd] = R[rs] + R[rt];
						break;
					case FNSUB:
						printf("\nExecuting: sub $%d, $%d, $%d\n", rd, rs, rt);
						R[rd] = R[rs] - R[rt];
						break;
					case FNAND:
						printf("\nExecuting: and $%d, $%d, $%d\n", rd, rs, rt);
						R[rd] = R[rs] & R[rt];
						break;
					case FNOR:
						printf("\nExecuting: or $%d, $%d, $%d\n", rd, rs, rt);
						R[rd] = R[rs] | R[rt];
						break;
					case FNSLT:
						printf("\nExecuting: slt $%d, $%d, $%d\n", rd, rs, rt);
						if(R[rs] < R[rt]) {
							R[rd] = 1;
						}
						else {
							R[rd] = 0;
						}
						break;
					default:
						printf("\n!!! Unknown funct: %d !!!\n", fn);
				}
				break;
			case OPLW:
				printf("\nExecuting: lw $%d, $%d(%d)\n", rt, rs, im);
				R[rt] = readword( R[rs] + im );
				break;
			case OPSW:
				printf("\nExecuting: sw $%d, $%d(%d)\n", rt, rs, im);
				writeword( R[rs] + im, R[rt] );
				break;
			case OPBEQ:
				printf("\nExecuting: beq $%d, $%d, %d\n", rs, rt, im);
				if( R[rs] == R[rt] ) {
					PC = PC + (im << 2);
				}
				break;
			case OPJ:
				printf("\nExecuting: j %d\n", ad);
				PC = (ad << 2) | (PC & (0xf << 28));
				break;
			default:
				printf("\n!!! Unknown Opcode: %d !!!\n", op);
		}

		showregs();
	}

	return 0;
}

