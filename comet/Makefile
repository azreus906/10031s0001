#--------------------------------------------------------------------
# 変数定義
#--------------------------------------------------------------------

# リンカ指定
LD = gcc
LDFLAGS = 

# コンパイラ指定
CC = gcc
CFLAGS = -Wall

# 生成する実行ファイル名
BIN = comet

# ソースファイル名
SRC = comet.c cm_pchk.c cm_tbad.c cm_efrd.c cm_run.c cm_ld.c cm_st.c cm_adda.c cm_sll.c cm_exit.c cm_trls.c cm_erhd.c

# オブジェクトファイル名
OBJ = $(SRC:.c=.o)

#--------------------------------------------------------------------
# ターゲット，依存関係，アクション定義
#--------------------------------------------------------------------

# リンク
$(BIN) : $(OBJ)
	$(LD) -o $(BIN) $(OBJ) $(LDFLAGS)

# コンパイル
.c.o:
	$(CC) -c $(CFLAGS) $<

# コマンド
depend:
	makedepend -- $(CFLAGS) -- $(SRC)
clean:
	rm -f $(BIN) $(OBJ)

# DO NOT DELETE
