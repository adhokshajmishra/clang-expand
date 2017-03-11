#ifndef CLANG_EXPAND_COMMON_ROUTINES_HPP
#define CLANG_EXPAND_COMMON_ROUTINES_HPP

// Project includes
#include "clang-expand/common/call-data.hpp"


// Standard includes
#include <iosfwd>
#include <optional>

namespace clang {
class SourceLocation;
class SourceManager;
class LangOptions;
class SourceRange;
class FunctionDecl;
class ASTContext;
}

namespace llvm {
class Twine;
}

namespace ClangExpand {
struct DefinitionData;
class Query;
}

namespace ClangExpand::Routines {
using OptionalCall = std::optional<CallData>;

bool locationsAreEqual(const clang::SourceLocation& first,
                       const clang::SourceLocation& second,
                       const clang::SourceManager& sourceManager);

std::string getSourceText(const clang::SourceRange& range,
                          clang::SourceManager& sourceManager,
                          const clang::LangOptions& languageOptions);

std::string
getSourceText(const clang::SourceRange& range, clang::ASTContext& context);

DefinitionData collectDefinitionData(const clang::FunctionDecl& function,
                                     clang::ASTContext& context,
                                     const Query& query);

std::string makeAbsolute(const std::string& filename);

[[noreturn]] void error(const char* message);
[[noreturn]] void error(llvm::Twine&& twine);

}  // namespace ClangExpand::Routines


#endif  // CLANG_EXPAND_COMMON_ROUTINES_HPP
