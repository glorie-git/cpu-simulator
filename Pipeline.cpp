//
//  Pipeline.cpp
//  CPU_Simulator
//
//  Created by _anotherone on 2020-07-23.
//  Copyright © 2020 Glorie Ramazani. All rights reserved.
//

#include "Pipeline.hpp"

Pipeline::Pipeline(){
    PC = 0;
    ROB_ID = 0;
    reorderBuffer.reserve(FETCH_WIDTH);
    branchDetected = false;
    already_fecthed = 0;
    done = false;
    debug = false;
    committed = 0;
    filename = "";
}

void Pipeline::print_stats(){
    cout << "Average latency per instruction: ";
    cout << stats->get_latency() << endl;
    cout << "Average throughput per instruction: ";
    cout << stats->get_throughput() << endl;
}

Pipeline::~Pipeline(){
    delete memory;
    delete IQ;
    delete registerFile;
}

void Pipeline::addinst_rob(rob_inst* x){
    reorderBuffer.push_back(x);
}

bool Pipeline::isempty_IQ(){
    if (IQ->iqueue.size() > 0)
        return false;
    else
        return true;
}

bool Pipeline::isempty_ROD(){
    if (reorderBuffer.size() > 0)
        return false;
    else
        return true;
}

void Pipeline::fetch(){
    //stats->increment_clock();
    unsigned int tmp;
    if (IQ->iqueue.size() < FETCH_WIDTH && reorderBuffer.size() < FETCH_WIDTH && !done){
        if (debug)
            cout << "--------------- FETCH ---------------\n";
        for (int i = 0; IQ->iqueue.size() < FETCH_WIDTH && !done && reorderBuffer.size() < FETCH_WIDTH; i++) {
            stats->increment_clock();
            Instruction * inst = new Instruction;
            instQ * instq = new instQ;
            rob_inst * instr = new rob_inst;
            tmp = memory->get_instr(PC);//instruction_memory[PC];
            already_fecthed++;
            inst->decode(tmp);
        
          
            if (debug) {
                inst->print_instruction();
                cout << endl;
            }
        
            if (!inst->j_type){//} && !branchDetected){//|| inst->get_opcode() != 5 || inst->get_opcode() != 6 ) {
                instq->dest = inst->get_dest();
                instq->immediate = inst->get_immediate();
                instq->src1 = inst->get_src1();
                instq->src2 = inst->get_src2();
                instq->operation = inst->get_opcode();
                instq->type = inst->get_type_();
                instq->ROB_ID = ROB_ID;
                instr->instruction = memory->get_instr(PC);//instruction_memory[PC];
                instr->ROB_ID = ROB_ID;
                addinst_rob(instr);
            
                if ( instq->dest != instq->src1)
                    registerFile->set_stat(0, instq->dest);
                else
                    registerFile->set_stat(1, instq->dest);
            
                if ( instq->src1 >= -1) {
                    if ( instq->src1 != -1 ){
                        if ( registerFile->get_stat(instq->src1) == 1 )
                            { instq->valid1 = 1; }
                        else
                            { instq->valid1 = 0; }
                    }
                    else
                        { instq->valid1 = 1; }
                }
            
                
            if ( instq->src2 >= -1 ) {
                if ( instq->src2 != -1 ){
                    if ( registerFile->get_stat(instq->src2) == 1 )
                        {  instq->valid2 = 1; }
                    else
                        { instq->valid2 = 0; }
                }
                else
                    { instq->valid2 = 1; }
            }
                

            IQ->addInst(instq);
            ROB_ID++;
            
            if (inst->get_opcode() == 5 || inst->get_opcode() == 6){
                if (debug)
                    cout << "Branch code detected...\n";
                branchDetected = true;
                       /*  go to execute mode */
                execute();
                if (debug)
                    cout << "--------------- FETCH ---------------\n";
                //break;
                   }
            /*  fetch next instruction  */
                //if ( branchDetected ) {
                    PC++;
                    //branchDetected = false;
                //}
                if (!(already_fecthed < memory->get_num_instrs()))
                    done = true;
        }
        else if ( inst->j_type )
            /*  if j type jump to PC = inst->immediate  */
            { PC = inst->get_immediate();}
    }
        if (debug)
            IQ->printIQ();
    }
}

void Pipeline::commit(){
    stats->increment_clock();
    int text = 0;
    if ( reorderBuffer.size() > 0 ) {
        if ( debug )
            cout << "--------------- COMMIT ---------------\n";
        vector<rob_inst*>::iterator it = reorderBuffer.begin();
        //while ( reorderBuffer.size() > 0) {
        for (int i = 0; i < COMMIT_WIDTH ; i++){
            if (reorderBuffer[0]->vald_bit == 1 && committed < memory->get_num_instrs()) {
                if ( debug )
                    cout << "Committing ROB INST " << reorderBuffer[0]->instruction << endl;
                reorderBuffer.erase(it);
                committed++;
                text++;
            }
            else if(reorderBuffer.size() > 0 && debug) {
                if ( i > 0 ) {
                    cout << "Instruction "<< reorderBuffer[0]->instruction <<" possibly in entanglement\n";
                    cout << "Not ready to commit\n\n";
                }
                else {
                    cout << "Instructions are possibly in entanglements\n";
                    cout << "None ready to commit\n\n";
                }
                break;
            }
        }
    }
    if (debug)
        cout << endl;
}

void Pipeline::print_inst(int opcode,int dest, int reg1, int reg2, int immediate, int type){
    
    string op;
    string val;
    
    if ( type == 4 || type == 3 || opcode == 5 || opcode == 6 )
        val = ", #"+to_string(immediate);
    else
        val = ", r"+to_string(reg2);
    
    switch (opcode) {
        case ADD :
            op = "#add";
                    break;
        case ADDI :
            op = "#addi";
                  break;
        case SUB :
            op = "#sub";
                    break;
        case SUBI :
            op = "#subi";
                    break;
        case MUL :
            op = "#mul";
                    break;
        case MULI :
            op = "#muli";
                    break;
        case DIV :
            op = "#div";
                    break;
        case DIVI :
            op = "#divi";
                      break;
        case MOD :
            op = "#mod";
                    break;
        case MODI :
             op = "#modi";
                    break;
        case BNE :
             op = "#bne";
                    break;
        case BEQ :
             op = "#beq";
                    break;
        case MOV :
            if (opcode == 8)
                op = "#prnt";
            else
                op = "#mov";
            break;
        case PARAM :
            op = "#param";

        default:
                    break;
    }
    
    cout << "[EXE]: "<< op << " r" << dest ;
    if ( type != 4 && type != 7)
        cout << ", r" << reg1 << val << endl;
    else
        cout << val << endl;
}

void Pipeline::execute(){
    stats->increment_clock();
    int result = 0;
    int src1 = 0;
    int src2 = 0;
    int dest = 0;
    int reg1 = 0;
    int reg2 = 0;
    int immediate = 0;
    int ROD_counter = 0;
    
    if (IQ->iqueue.size() > 0 || reorderBuffer.size() > 0) {
        if ( debug )
            cout << "--------------- EXECUTE ---------------\n";
        do {
            if ( (IQ->iqueue[0]->valid1 == 1 && IQ->iqueue[0]->valid2 == 1)){//} || branchDetected){
                for (int i = 0; i < ISSUE_WIDTH; i++) {
                    if ( IQ->iqueue.size() > 0) {
                        if (debug) {
                            cout << "Checking status src1 R" << IQ->iqueue[0]->src1 << ", V=" << IQ->iqueue[0]->valid1 << endl;
                            cout << "Checking status src2 R" << IQ->iqueue[0]->src2 << ", V=" << IQ->iqueue[0]->valid2 << endl;
                            cout << "Inst: " << reorderBuffer[ROD_counter]->instruction << " ) : Ready for execution\n";
                        }
                        if ( IQ->iqueue[0]->valid1 == 1 && IQ->iqueue[0]->valid2 == 1){
                            //src1 = registerFile->get_dval(IQ->iqueue[0]->src1);
                            
                            if ( IQ->iqueue[0]->src1 != -1 ) {
                                src1 = registerFile->get_dval(IQ->iqueue[0]->src1); }
                            else
                                src1 = 0;
                            
                            if ( IQ->iqueue[0]->src2 != -1 ) {
                                src2 = registerFile->get_dval(IQ->iqueue[0]->src2); }
                            else
                                src2 = 0;
                            
                            if ( IQ->iqueue[0]->src1 != -1 ) {
                                src1 = registerFile->get_dval(IQ->iqueue[0]->src1); }
                            else
                                src1 = 0;
                            
                            reg1 = IQ->iqueue[0]->src1;
                            reg2 = IQ->iqueue[0]->src2;
                            
                            dest = IQ->iqueue[0]->dest;
                            immediate = IQ->iqueue[0]->immediate;
                            int exeOpcode = IQ->iqueue[0]->operation;
                            
                            if (debug)
                                print_inst(exeOpcode, dest, reg1, reg2, immediate, IQ->iqueue[0]->type);
                            
                            result = Execute::execute(src1, src2, dest, immediate, PC, exeOpcode);
                        
                            /*      Writeback the result to the register file    */
                            if ( IQ->iqueue[0]->operation != BNE && IQ->iqueue[0]->operation != BEQ ){
                                if (debug) {
                                    if ( IQ->iqueue[0]->type == 4)
                                        cout << "Writing " << immediate << " to R" << dest << endl;
                                    else
                                        cout << "Writing " << result << " to R" << dest << endl;
                                }
                            }
                                registerFile->set_dval(result, dest);
                                registerFile->set_stat(1, dest);
                                                            
                            if (debug)
                                cout << "Executed\n";
                            stats->increment_executed();
                            /*      Deleting entry from the IQ    */
                            vector<instQ*>::iterator it = IQ->iqueue.begin();
                            IQ->iqueue.erase(it);
                            
                            /*      Marking instruction as executed in the ROB    */
                            reorderBuffer[ROD_counter]->vald_bit = 1;
                            
                            if (debug)
                                cout << "ROB " << reorderBuffer[ROD_counter]->instruction << " marked.\n\n";
                            
                            /*      “Broadcast” the writeback register to the IQ    */
                            for (int i = 0; i < IQ->iqueue.size(); i++){
                                if (IQ->iqueue[i]->src1 == dest)
                                    IQ->iqueue[i]->valid1 = 1;
                                    
                                if (IQ->iqueue[i]->src2 == dest)
                                    IQ->iqueue[i]->valid2 = 1;
                            }
                            
                            if (IQ->iqueue[0]->operation == 8) {
                                cout << "Final result: " << result << endl;
                            }
                            ROD_counter++;
                        }
                    }
                }
            }
            else if(debug) {
                cout << "Checking status src1 R" << IQ->iqueue[0]->src1 << ", V=" << IQ->iqueue[0]->valid1 << endl;
                cout << "Checking status src2 R" << IQ->iqueue[0]->src2 << ", V=" << IQ->iqueue[0]->valid2 << endl;
                cout << "Inst: " << reorderBuffer[ROD_counter]->instruction << " ) : Not ready for execution\n\n";
            }
        } while (IQ->iqueue.size() != 0 && IQ->iqueue[0]->valid1 == 1 && IQ->iqueue[0]->valid2 == 1);
    }
}

void Pipeline::initiate_pipeline(string fname){
    memory->read_file(fname);
    stats->set_total(memory->get_num_instrs());
}

void Pipeline::reset(){
    PC = 0;
    ROB_ID = 0;
    branchDetected = false;
    already_fecthed = 0;
    done = false;
    debug = false;
    committed = 0;
    filename = "";
    
    IQ->iqueue.clear();
    memory->reset();
    registerFile->reset();
    reorderBuffer.clear();
    stats->reset();
}

void Pipeline::start(bool xx){
    debug = xx;
    
    do {
        commit();
        execute();
        fetch();
    } while (!isempty_IQ() || !isempty_ROD());
    
    
    /*  STAGE 1 */
    /*1.  Instruction Fetch (IF)  */
    //fetch();
    
    /*2.  Instruction Decode (ID)  */
    //decode(inst,PC);
    
    /*  Instruction Queue (IQ) updating */
    
    
    /*  Reorder Buffer (ROB) updating */
    
    /*  STAGE 2 */
    /*1.  Dispatch  */
    /*  the instruction is released from the IQ */
    
    /*2.  Read (Rd)  */
    /*  input operands are read from the register file */
    
    /*3.  Execute (EXE)  */
    /*  operation is executed using source operand data */
    
    /*4.  Writeback (WB)  */
    /*  result is written back to the register file at the instruction’s specified destination register */
    
    /*5.  Broadcasting  */
    /*  the destination register is broadcasted to the IQ to inform younger instructions that the contents in the register are ready to be read. */
    
    /*  STAGE 3 */
    /*1.  Commit  */
}
