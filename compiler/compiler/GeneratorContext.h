#ifndef _GENERATOR_CONTEXT_H
#define _GENERATOR_CONTEXT_H

#include <stack>

#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Support/TargetRegistry.h"

#include "AbstractSyntaxTree.h"
#include "Registry.h"

using namespace llvm;

class GeneratorBlock
{
    public:
        LocalRegistry* locals;
        GeneratorBlock() {
            locals = new LocalRegistry();
        }

        BasicBlock* block;
        Value* ret;
};

class GeneratorContext
{
    std::stack<GeneratorBlock*> block_stack;
    LLVMContext context;
    Function* entry_point;

    //std::map<std::string, 

    public:
        Module* module;
        llvm::Type* i1, *i8, *i8_ptr, *i32, *i64, *void_, *double_;

        GeneratorContext();
        void generate(Block& root);

        llvm::Type* typeof(const Identifier& type);
        void __stdlib_registry();

        LLVMContext& getctx() {
            return context;
        }

        GeneratorBlock* current_block() {
            return block_stack.top();
        }

        LocalRegistry* locals() {
            return block_stack.top()->locals;
        }

        void push(BasicBlock* block) 
        {
            GeneratorBlock* gbl = new GeneratorBlock();
            gbl->ret = nullptr;
            if (block == nullptr) {
                block = llvm::BasicBlock::Create(context, "scope");
            }

            gbl->block = block;
            block_stack.push(gbl);
        }

        void pop() 
        {
            auto* it = block_stack.top();
            block_stack.pop();
            delete it;
        }
};

#endif // !_GENERATOR_CONTEXT_H
