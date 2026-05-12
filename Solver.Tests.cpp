#include "CppUnitTest.h"
#include "../Solver/queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTests
{
	TEST_CLASS(SolverTests)
	{
	public:
		
		TEST_METHOD(Creat_using_list_success)
		{
			//Arrage
			const int s = 3;
			const int* list = new int[s] {1, 2, 3};

			//Act
			queue q(s, list);

			//Assert
			Assert::AreEqual(q.get_size(), s);
			Assert::AreEqual(q.get_front(), 0);
			Assert::AreEqual(q.get_back(), s - 1);
			Assert::AreEqual(q.get_val(0), list[0]);
			Assert::AreEqual(q.get_val(1), list[1]);
			Assert::AreEqual(q.get_val(2), list[2]);
		}
		TEST_METHOD(Insert_value)
		{
			//Arrage
			const int s = 3;
			const int* list = new int[s] {1, 2, 3};
			queue q(s, list);

			//Act
			q.insert(0, 0);

			//Assert
			Assert::AreEqual(q.get_val(0), 0);
			Assert::AreEqual(q.get_val(1), 1);
			Assert::AreEqual(q.get_val(2), 2);
			Assert::AreEqual(q.get_val(3), 3);
		}
		TEST_METHOD(Remove_value)
		{
			//Arrage
			const int s = 3;
			const int* list = new int[s] {1, 2, 3};
			queue q(s, list);

			//Act
			q.remove(2);

			//Assert
			Assert::AreEqual(q.get_val(0), 1);
			Assert::AreEqual(q.get_val(1), 3);
		}
		TEST_METHOD(Insert_back)
		{
			//Arrage
			const int s = 3;
			const int* list = new int[s] {1, 2, 3};
			queue q(s, list);

			//Act
			q.insert_back(4);

			//Assert
			Assert::AreEqual(q.get_val(0), 1);
			Assert::AreEqual(q.get_val(1), 2);
			Assert::AreEqual(q.get_val(2), 3);
			Assert::AreEqual(q.get_val(3), 4);
		}
		TEST_METHOD(Search)
		{
			//Arrage
			const int s = 3;
			const int* list = new int[s] {1, 2, 3};
			queue q(s, list);

			//Act
			size_t result = q.search(1);
			int converted = static_cast<int>(result);

			//Assert
			Assert::AreEqual(converted, 0);
		}
		TEST_METHOD(Is_empty)
		{
			//Arrage
			queue q;
			//Act
			bool result = q.empty();
			//Assert
			Assert::IsTrue;
		}
	};
}
