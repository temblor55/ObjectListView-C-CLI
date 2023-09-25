#pragma once

namespace datagridtreeview {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace BrightIdeasSoftware;
	using namespace std;

	ref class MyForm;

	// Define the Node class
	public ref class Node {
	public:
		String^ Name;
		String^ Column1;
		String^ Column2;
		String^ Column3;
		List<Node^>^ Children;

		Node(String^ name, String^ col1, String^ col2, String^ col3) {
			Name = name;
			Column1 = col1;
			Column2 = col2;
			Column3 = col3;
			Children = gcnew List<Node^>();
		}
	};

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			InitializeData();
			FillTree();
			//
			//TODO: Add the constructor code here
			//

		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private: BrightIdeasSoftware::TreeListView^ treeListView1;
		private: List<Node^>^ data;
		private: BrightIdeasSoftware::OLVColumn^ nameCol;
		private: BrightIdeasSoftware::OLVColumn^ col1;
		private: BrightIdeasSoftware::OLVColumn^ col2;
		private: BrightIdeasSoftware::OLVColumn^ col3;

		System::ComponentModel::IContainer^ components;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->treeListView1 = (gcnew BrightIdeasSoftware::TreeListView());
			this->nameCol = (gcnew BrightIdeasSoftware::OLVColumn());
			this->col1 = (gcnew BrightIdeasSoftware::OLVColumn());
			this->col2 = (gcnew BrightIdeasSoftware::OLVColumn());
			this->col3 = (gcnew BrightIdeasSoftware::OLVColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->treeListView1))->BeginInit();
			this->SuspendLayout();
			this->treeListView1->AllColumns->Add(this->nameCol);
			this->treeListView1->AllColumns->Add(this->col1);
			this->treeListView1->AllColumns->Add(this->col2);
			this->treeListView1->AllColumns->Add(this->col3);
			this->treeListView1->CellEditUseWholeCell = false;
			this->treeListView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
			this->nameCol, this->col1,
			this->col2, this->col3
			});
			this->treeListView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->treeListView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeListView1->HideSelection = false;
			this->treeListView1->Location = System::Drawing::Point(0, 0);
			this->treeListView1->Name = L"treeListView1";
			this->treeListView1->ShowGroups = false;
			this->treeListView1->Size = System::Drawing::Size(419, 245);
			this->treeListView1->TabIndex = 0;
			this->treeListView1->UseCompatibleStateImageBehavior = false;
			this->treeListView1->View = System::Windows::Forms::View::Details;
			this->treeListView1->VirtualMode = true;
			this->nameCol->AspectName = L"Name";
			this->nameCol->Text = L"Name";
			this->nameCol->Width = 150;
			this->col1->Text = L"Column1";
			this->col2->Text = L"Column2";
			this->col3->Text = L"Column3";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(419, 245);
			this->Controls->Add(this->treeListView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->treeListView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		   void InitializeData()
		   {
			   // Create fake nodes.
			   Node^ parent1 = gcnew Node("PARENT1", "-", "-", "-");
			   parent1->Children->Add(gcnew Node("CHILD_1_1", "A", "X", "1"));
			   parent1->Children->Add(gcnew Node("CHILD_1_2", "A", "Y", "2"));
			   parent1->Children->Add(gcnew Node("CHILD_1_3", "A", "Z", "3"));

			   Node^ parent2 = gcnew Node("PARENT2", "-", "-", "-");
			   parent2->Children->Add(gcnew Node("CHILD_2_1", "B", "W", "7"));
			   parent2->Children->Add(gcnew Node("CHILD_2_2", "B", "Z", "8"));
			   parent2->Children->Add(gcnew Node("CHILD_2_3", "B", "J", "9"));

			   Node^ parent3 = gcnew Node("PARENT3", "-", "-", "-");
			   parent3->Children->Add(gcnew Node("CHILD_3_1", "C", "R", "10"));
			   parent3->Children->Add(gcnew Node("CHILD_3_2", "C", "T", "12"));
			   parent3->Children->Add(gcnew Node("CHILD_3_3", "C", "H", "14"));

			   data = gcnew List<Node^>();
			   data->Add(parent1);
			   data->Add(parent2);
			   data->Add(parent3);
		   }

		   bool CanExpand(Object^ model)
		   {
			   return (dynamic_cast<Node^>(model))->Children->Count > 0;
		   }

		   System::Collections::IEnumerable^ GetChildren(System::Object^ model)
		   {
			   List<System::Object^>^ children = gcnew List<System::Object^>();
			   auto node = dynamic_cast<Node^>(model);
			   if (node != nullptr)
			   {
				   for each (Node ^ child in node->Children)
				   {
					   children->Add(child);
				   }
			   }
			   return children;
		   }

		   Object^ GetName(Object^ model)
		   {
			   return (dynamic_cast<Node^>(model))->Name;
		   }

		   Object^ GetColumn1(Object^ model)
		   {
			   return (dynamic_cast<Node^>(model))->Column1;
		   }

		   Object^ GetColumn2(Object^ model)
		   {
			   return (dynamic_cast<Node^>(model))->Column2;
		   }

		   Object^ GetColumn3(Object^ model)
		   {
			   return (dynamic_cast<Node^>(model))->Column3;
		   }

		   void FillTree()
		   {
			   // Set the delegate that the tree uses to know if a node is expandable.
			   treeListView1->CanExpandGetter = gcnew BrightIdeasSoftware::TreeListView::CanExpandGetterDelegate(this, &MyForm::CanExpand);

			   // Set the delegate that the tree uses to know the children of a node.
			   treeListView1->ChildrenGetter = gcnew BrightIdeasSoftware::TreeListView::ChildrenGetterDelegate(this, &MyForm::GetChildren);

			   // set up the delegates.
			   nameCol->AspectGetter = gcnew AspectGetterDelegate(this, &MyForm::GetName);
			   col1->AspectGetter = gcnew AspectGetterDelegate(this, &MyForm::GetColumn1);
			   col2->AspectGetter = gcnew AspectGetterDelegate(this, &MyForm::GetColumn2);
			   col3->AspectGetter = gcnew AspectGetterDelegate(this, &MyForm::GetColumn3);

			   // Set the tree roots.
			   treeListView1->Roots = data;
			   treeListView1->ExpandAll();

		   }

	};
}
